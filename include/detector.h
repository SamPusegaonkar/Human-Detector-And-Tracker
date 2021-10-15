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
#include <opencv4/opencv2/opencv.hpp>
#include "../include/camera.h"
#include "../include/obstacle.h"

class Detector: public Camera {
 private:
  float confidence_;
  std::string model_file_;
  std::string classes_;
  std::vector<float> trackers_;
  Camera cam_;

 public:
  bool LoadModel(std::string file_name);
  void Detect();
  std::vector<int> GetBoundingBoxes(cv::Mat frame);
  std::vector<Obstacle> DefineObstacles(std::vector<int> coordinates);
  cv::Mat WriteRobotCoordinatesOnFrame(std::vector<Obstacle>, cv::Mat frame);
  ~Detector() {}
};
