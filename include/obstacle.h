/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Obstacle {
 private:
  std::string label_;
  float camera_x_position_;
  float camera_z_position_;
  float robot_x_position_;
  float robot_y_position_;
  float human_height_;
  int obstacle_width_;
  int obstacle_height_;

 public:
  Obstacle();
  void ComputeDepth(float focal_length);
  void ComputeHorizontalPosition();
  std::vector<Obstacle> GetRobotFrameCoordinates(std::vector<Obstacle> obstacle,
  std::vector<int> transformation_matrix);
  ~Obstacle();
};
