/**
 * @file detector.h
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Detector class used to process video feed and detect/track obstacles
 * @version 0.1
 * @date 2021-10-14
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "../include/obstacle.h"
#include "../include/camera.h"


/**
 * @brief A class to detect humans.
 */
class Detector: public Camera {
 private:
  float confidence_;
  std::string model_file_;
  Camera cam_;

 public:
   /**
   * @brief Construct a new Detector:: Detector object
   */
  Detector() : model_file_{""} {
    this->confidence_ = 0.7f;
  }

  /**
   * @brief Load the human detection model.
   * @param file_name of string type.
   * @return true If the file is present & valid.
   * @return false If the file is not present or valid.
   */ 
  bool LoadModel(const std::string& file_name);

  /**
   * @brief A method to run the model to detect humans using mobilenet.
   * @param frame Frame.
   * @return std::vector<std::vector<double>> Returns the position in robot frame.
   */
  std::vector<std::vector<double>> Detect(cv::Mat frame);

  /**
   * @brief Will retrive bounding boxes of the detected human.
   * @param frame Image.
   * @return std::vector<std::vector<int>> Bounding boxes.
   */
  std::vector<std::vector<int>> GetBoundingBoxes(cv::Mat frame);

  /**
   * @brief Creates an Obstacle instance for each obstacle detected.
   * @param coordinates Bounding boxes.
   * @return std::vector<Obstacle> A vector of Obstacle instances.
   */
  std::vector<Obstacle> DefineObstacles(
    std::vector<std::vector<int>> coordinates);

  ~Detector() {}
};
