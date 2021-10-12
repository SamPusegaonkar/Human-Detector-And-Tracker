/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
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
  Detector::~Detector() {}
};
