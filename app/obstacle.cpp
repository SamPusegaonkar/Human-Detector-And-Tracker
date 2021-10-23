/**
 * @file obstacle.cpp
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Obstacle class used to store detected obstacle positions
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "../include/obstacle.h"

/**
 * @brief Setter for obstacle width
 * 
 * @param width Width of obstacle bounding box
 */
void Obstacle::SetObstacleWidth(int width) {
    obstacle_width_ = width;
}

/**
 * @brief Setter for obstacle height
 * 
 * @param height Height for obstacle bounding box
 */
void Obstacle::SetObstacleHeight(int height) {
    obstacle_height_ = height;
}

/**
 * @brief Compute the obstacle distance with respect to the camera frame.
 * 
 * @param focal_length Focal length of camera.
 */
void Obstacle::ComputeDepth(float focal_length) {
    camera_z_position_ = (human_height_ * focal_length) / obstacle_height_;
}

/**
 * @brief Compute the horizontal position of object with respect to the center of the camera frame.
 * 
 */
void Obstacle::ComputeHorizontalPosition(float horizontal_fov) {
    camera_x_position_ = camera_z_position_ * atan(horizontal_fov / 2);
}

/**
 * @brief Get the objects position in the Robot Frame.
 * 
 * @param transformation_matrix Transformation matrix to go from Camera frame to Robot frame.
 * @return std::vector<float> Detected Obstacle.
 */
std::vector<double> Obstacle::GetRobotFrameCoordinates(
        std::vector<std::vector< double> > &transformation_matrix) {
    // Position of Obstacle in Camera frame
    Eigen::Matrix<double, 4, 1> position{
        {camera_x_position_},
        {0},
        {camera_z_position_},
        {1}};

    Eigen::MatrixXd transform(4, 4);
    for (int i = 0; i < transformation_matrix.size(); ++i)
        transform.row(i) = Eigen::VectorXd::Map(&transformation_matrix[i][0],
            transformation_matrix[0].size());

    auto pos_in_rframe_v = transform * position;
    robot_x_position_ = pos_in_rframe_v[0];
    robot_y_position_ = pos_in_rframe_v[1];
    std::vector<double> pos_in_rframe{robot_x_position_, robot_y_position_};

    return pos_in_rframe;
}

// int main() {
//     std::vector<std::vector<double> > transformation_matrix{
//         {0.0, 0.0, -1.0, 0.5},
//         {-1.0, 0.0, 0.0, 0.0},
//         {0.0, -1.0, 0.0, 0.5},
//         {0.0, 0.0, 0.0, 1.0}};

//     float focal_length{0.00367};
//     float horizontal_fov{1.0472};  // 60 deg in Radians
//     Obstacle o;
//     // o.SetObstacleHeight(1312*2);
//     // o.SetObstacleWidth(1260*2);
//     // o.ComputeDepth(focal_length);
//     o.ComputeHorizontalPosition(horizontal_fov);
//     // std::cout << o.getDepth() << std::endl;
//     auto pos = o.GetRobotFrameCoordinates(transformation_matrix);
//     std::cout << pos[0] << std::endl;
//     std::cout << pos[1] << std::endl;

// }
