/**
 * @file detector.h
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Detector class used to process video feed and detect/track obstacles
 * @version 0.1
 * @date 2021-10-14
 * 
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

class Detector: public Camera {
 private:
  float confidence_;
  std::string model_file_;
  std::string classes_;
  std::vector<float> trackers_;
  Camera cam_;

 public:
  // TO DO: Define actual initialization values
  /**
   * @brief Construct a new Detector:: Detector object
   * 
   */
  Detector() {
      float confidence_{0};
      std::string model_file_{0};
      std::string classes_{0};
      std::vector<float> trackers_{0};
      Camera cam_;
  }
  bool LoadModel(std::string file_name);
  std::vector<std::vector<double>> Detect(cv::Mat frame);
  std::vector<std::vector<int>> GetBoundingBoxes(cv::Mat frame);
  std::vector<Obstacle> DefineObstacles(std::vector<std::vector<int>> coordinates);
  cv::Mat WriteRobotCoordinatesOnFrame(std::vector<Obstacle>, cv::Mat frame);
  ~Detector() {}
};
