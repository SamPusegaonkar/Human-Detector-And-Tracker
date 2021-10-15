/**
 * @file obstacle_test.cpp
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Unit tests the Obstacle class methods
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include "../include/obstacle.h"

/**
 * @brief Test the transformation for the obstacle position 
 * from the camera frame to the robot frame
 * 
 */
TEST(Obstacle_Test, position_in_robot_frame) {
    std::vector<std::vector<double> > transformation_matrix{
          {0.0, 0.0, -1.0, 0.5},
          {-1.0, 0.0, 0.0, 0.0},
          {0.0, -1.0, 0.0, 0.5},
          {0.0, 0.0, 0.0, 1.0}};

    Obstacle pos_test_obstacle;
    float focal_length{30};
    pos_test_obstacle.ComputeDepth(focal_length);
    pos_test_obstacle.ComputeHorizontalPosition();
    // std::vector<double> expected_pos{2.5, -3};
    std::vector<double> expected_pos{0.5, 0.5};
    EXPECT_EQ(expected_pos,
        pos_test_obstacle.GetRobotFrameCoordinates(transformation_matrix));
}
