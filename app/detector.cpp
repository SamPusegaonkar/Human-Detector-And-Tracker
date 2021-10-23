/**
 * @file detector.cpp
 * @author Sameer Pusegaonkar & Shon Cortes
 * @brief A file which implements methods to detect humans
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */


#include <fstream>
#include <iostream>
#include <string>

#include "../include/camera.h"
#include "../include/detector.h"

/**
 * @brief Load the human detection model.
 * @param file_name 
 * @return true If the file is present & valid
 * @return false If the file is not present or valid 
 */
bool Detector::LoadModel(std::string file_name) {
  std::string model_file_binary = file_name + ".caffemodel";
  std::string model_file_text = file_name + ".prototxt";
  this->model_file_ = file_name;
  return std::ifstream(model_file_binary) && std::ifstream(model_file_text);
}

/**
 * @brief A method to run detect humans using mobilenet.
 * @param img 
 * @return std::vector<std::vector<double>> 
 */
std::vector<std::vector<double>> Detector::Detect(cv::Mat img) {
  // Gets all the bounding boxes
  auto detections = this->GetBoundingBoxes(img);
  auto obstacles = this->DefineObstacles(detections);
  std::vector<std::vector<double>> positions;

  for (auto i = 0; i < detections.size(); i++) {
    auto obstacle = obstacles[i];
    auto detection = detections[i];

    obstacle.ComputeDepth(cam_.focal_length_);
    obstacle.ComputeHorizontalPosition(cam_.horizontal_fov_);

    auto robot_pos = obstacle.GetRobotFrameCoordinates(
        cam_.transformation_matrix_);
    positions.push_back(robot_pos);

    int box_x = detection[0];
    int box_y = detection[1];
    int box_width = detection[2];
    int box_height = detection[3];

    cv::rectangle(img, cv::Point(box_x, box_y),
      cv::Point(box_x + box_width, box_y + box_height),
      cv::Scalar(255, 255, 255), 2);

    std::string text = "Human x: " +
      std::to_string(robot_pos[0]) +
      "y: " + std::to_string(robot_pos[1]);

    cv::putText(img, text, cv::Point(box_x, box_y - 5),
      cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 255), 1);
  }

  return positions;
}

/**
 * @brief Creates an Obstacle instance for each obstacle detected.
 * @param coordinstart webcam &ates Bounding box coordinates to be used in 
 * calculating the obstacle position in the Camera frame.
 * @return std::vector<Obstacle> A vector of Obstacle instances.
 */
std::vector<std::vector<int>> Detector::GetBoundingBoxes(cv::Mat img) {
  auto model =
    cv::dnn::readNetFromCaffe(this->model_file_ + ".prototxt",
                              this->model_file_ + ".caffemodel");

  std::vector<std::vector<int>> detections;
  int image_height = img.cols;
  int image_width = img.rows;

  //  Create blob from image
  auto blob = cv::dnn::blobFromImage(img, 0.007843,
                                      cv::Size(300, 300),
                                      cv::Scalar(127.5, 127.5, 127.5),
                                      true, false);

  //  create blob from image
  model.setInput(blob);

  // Forward pass through the model to carry out the detection
  cv::Mat output = model.forward();

  cv::Mat detectionMat(output.size[2], output.size[3],
                        CV_32F, output.ptr<float>());

  for (int i = 0; i < detectionMat.rows; i++) {
    int class_id = detectionMat.at<float>(i, 1);
    float confidence = detectionMat.at<float>(i, 2);

    // Check if the detection is of good quality
    if (confidence > this->confidence_) {
      int box_x =
        static_cast<int>(detectionMat.at<float>(i, 3) * img.cols);

      int box_y =
        static_cast<int>(detectionMat.at<float>(i, 4) * img.rows);

      int box_width =
        static_cast<int>(detectionMat.at<float>(i, 5) * img.cols - box_x);

      int box_height =
        static_cast<int>(detectionMat.at<float>(i, 6) * img.rows - box_y);

      detections.push_back({box_x, box_y, box_width, box_height});
    }
  }
  return detections;
}

std::vector<Obstacle> Detector::DefineObstacles(
  std::vector<std::vector<int>> coordinates) {
  std::vector<Obstacle> obstacles(coordinates.size());

  for (int i = 0; i < obstacles.size(); i++) {
    auto coordinate = coordinates[i];
    int box_width = coordinate[2];
    int box_height = coordinate[3];

    obstacles[i].SetObstacleWidth(box_width);
    obstacles[i].SetObstacleHeight(box_height);
  }
  return obstacles;
}

/**
 * @brief Writes the Obstacles coordinates, with respect to the 
 * robot coordinate frame, on the frame. 
 * @param frame Video frame being processed.
 * @return cv::Mat Video frame with coordinates displayed.
 */
cv::Mat Detector::WriteRobotCoordinatesOnFrame(const cv::Mat& frame) {
  cv::imshow("Video feed from Medibot", frame);
  return frame;
}
