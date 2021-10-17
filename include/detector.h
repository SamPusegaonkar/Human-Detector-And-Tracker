/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utils/trace.hpp>

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
  Detector() {
  float confidence_{0};
  std::string model_file_{0};
  std::string classes_{0};
  std::vector<float> trackers_{0};
  Camera cam_;
}
  bool LoadModel(std::string file_name);
  void Detect();
  std::vector<std::vector<int>> GetBoundingBoxes(cv::Mat frame);
  std::vector<Obstacle> DefineObstacles(std::vector<int> coordinates);
  cv::Mat WriteRobotCoordinatesOnFrame(std::vector<Obstacle>, cv::Mat frame);
  ~Detector();
};
