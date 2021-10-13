/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <xtensor-blas/xlinalg.hpp>
#include "../include/obstacle.h"

/**
 * @brief Construct a new Obstacle:: Obstacle object
 * 
 */
Obstacle::Obstacle() {
    std::string label_{"obstacle"};
    int id{0};
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
 * @param transformation_matrix Transformation matrix to go from Camera frame to Robot frame.
 * @return std::vector<float> Detected Obstacle.
 */
std::vector<float> Obstacle::GetRobotFrameCoordinates(
        std::vector<std::vector< float> > transformation_matrix) {
    std::vector<float> position{
        {camera_x_position_},
        {0},
        {camera_z_position_},
        {1}};
    std::vector<float> pos_in_rframe = xt::linalg::dot(
        transformation_matrix,
        position);
}

Obstacle::~Obstacle() {}
