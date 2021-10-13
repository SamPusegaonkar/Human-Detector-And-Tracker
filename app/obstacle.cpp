/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../include/obstacle.h"

Obstacle::Obstacle() {
    std::string label_{"default"};
    float camera_x_position_{0};
    float camera_z_position_{0};
    float robot_x_position_{0};
    float robot_y_position_{0};
    float human_height_{0};
    int obstacle_width_{0};
    int obstacle_height_{0};
}

// TO DO: Add detailed info on class method.
/**
 * @brief Compute the obstacle distance with respect to the camera frame.
 * 
 * @param focal_length Focal length of camera.
 */
void ComputeDepth(float focal_length) {}

// TO DO: Add detailed info on class method.
/**
 * @brief Compute the horizontal position of object with respect to the camera frame.
 * 
 */
void ComputeHorizontalPosition() {}

// TO DO: Add detailed info on class method.
/**
 * @brief Get the objects position in the Robot Frame.
 * 
 * @param obstacle 
 * @param transformation_matrix Transformation matrix to go from Camera frame to Robot frame.
 * @return std::vector<Obstacle> Detected Obstacle.
 */
std::vector<Obstacle> GetRobotFrameCoordinates(std::vector<Obstacle> obstacle,
                                 std::vector<int> transformation_matrix) {}
