/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#include <iostream>

#include "../include/camera.h"
#include "../include/detector.h"

Detector::Detector() {
  float confidence_{0};
  std::string model_file_{0};
  std::string classes_{0};
  std::vector<float> trackers_{0};
  Camera* cam_ = new Camera();
}


// TO DO: Add detailed info on class method.

/**
 * @brief Load the human detection model.
 * 
 * @param file_name 
 * @return true 
 * @return false 
 */
bool Detector::LoadModel(std::string file_name) {
/**LoadModel
 * @brief Process video feed and call the necessary functions to detect and track obstacles 
 * while returning their position in the robot frame.
 * 
 */
  std::string model_file_binary = file_name + ".caffemodel";
  std::string model_file_text = file_name + ".prototxt";
  auto net = cv::dnn::readNetFromCaffe(model_file_text, model_file_binary);
  return true;
}

/**
 * @brief Return a vector containing all detected obstacles.
 * 
 * @param frame Video frame being processed.
 * @return std::vector<int> Vector containing all detected obstacles.
 */
void Detector::Detect() {
  cv::VideoCapture cap;
  cap.open(0);
  if ( !cap.isOpened() ) {
    std::cout << "CANNOT OPEN CAM" << std::endl;
    return;
  }
  cv::Mat img;
  while ( true ) {
    cap >> img;
    resize(img, img, cv::Size(300, 300));
    cv::Mat inputBlob = cv::dnn::blobFromImage(img, 0.007843,
    cv::Size(300, 300),
    cv::Scalar(127.5, 127.5, 127.5), false);
    cv::imshow("Video Feed", img);
    if (cv::waitKey(10) == 27) break;
  }
}


std::vector<int> Detector::GetBoundingBoxes(cv::Mat frame) {}

// TO DO: Add detailed info on class method.
/**
 * @brief Creates an Obstacle instance for each obstacle detected.
 * 
 * @param coordinates Bounding box coordinates to be used in 
 * calculating the obstacle position in the Camera frame.
 * @return std::vector<Obstacle> A vector of Obstacle instances.
 */
std::vector<Obstacle> Detector::DefineObstacles(std::vector<int> coordinates) {}

// TO DO: Add detailed info on class method.
/**
 * @brief Writes the Obstacles coordinates, with respect to the 
 * robot coordinate frame, on the frame. 
 * 
 * @param frame Video frame being processed.
 * @return cv::Mat Video frame with coordinates displayed.
 */
cv::Mat Detector::WriteRobotCoordinatesOnFrame(std::vector<Obstacle>,
    cv::Mat frame) {}
