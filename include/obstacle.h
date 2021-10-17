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
  int id;
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
Obstacle() : label_("obstacle"),
    id{0},
    camera_x_position_{0.0f},
    camera_z_position_{0.0f},
    robot_x_position_{0.0f},
    robot_y_position_{0.0f},
    human_height_{0.0f},
    obstacle_width_{0},
    obstacle_height_{0} {
}
  void SetObstacleWidth(int width);
  void SetObstacleHeight(int height);
  void ComputeDepth(float focal_length);
  void ComputeHorizontalPosition();
  std::vector<double> GetRobotFrameCoordinates(
    std::vector<std::vector<double> > transformation_matrix);
  ~Obstacle() {}
};
