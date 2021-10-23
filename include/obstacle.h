/**
 * @file obstacle.h
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Obstacle class used to store detected obstacle positions
 * @version 0.1
 * @date 2021-10-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Obstacle {
 private:
  float camera_x_position_;
  float camera_z_position_;
  float robot_x_position_;
  float robot_y_position_;
  float human_height_;
  int obstacle_width_;
  int obstacle_height_;

 public:
 /**
 * @brief Construct a new Obstacle:: Obstacle object
 * 
 */
Obstacle() :
    camera_x_position_{0.0f},
    camera_z_position_{0.0f},
    robot_x_position_{0.0f},
    robot_y_position_{0.0f},
    human_height_{1.78f},  // Meters
    obstacle_width_{0},
    obstacle_height_{0} {
}
  void SetObstacleWidth(int width);
  void SetObstacleHeight(int height);
  void ComputeDepth(float focal_length);
  void ComputeHorizontalPosition(float horizontal_fov);
  std::vector<double> GetRobotFrameCoordinates(
    std::vector<std::vector<double> > &transformation_matrix);
  ~Obstacle() {}
};
