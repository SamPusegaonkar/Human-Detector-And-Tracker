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

/**
 * @brief A class to define all dimensions & coordinates of an obstacle.
 */
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

  /**
   * @brief Setter for obstacle width.
   * @param width Width of obstacle bounding box.
   */
  void SetObstacleWidth(int width);

  /**
   * @brief Setter for obstacle height.
   * @param height Height for obstacle bounding box.
   */
  void SetObstacleHeight(int height);

  /**
   * @brief Compute the obstacle distance with respect to the camera frame.
   * @param focal_length Focal length of camera.
   */
  void ComputeDepth(float focal_length);

  /**
   * @brief Compute the horizontal position of object with respect to the center of the camera frame.
   */
  void ComputeHorizontalPosition(float horizontal_fov);

  /**
   * @brief Get the objects position in the Robot Frame.
   * 
   * @param transformation_matrix Transformation matrix to go from Camera frame to Robot frame.
   * @return std::vector<float> Detected Obstacle.
   */
  std::vector<double> GetRobotFrameCoordinates(
    const std::vector<std::vector<double> > &transformation_matrix);
  ~Obstacle() {}
};
