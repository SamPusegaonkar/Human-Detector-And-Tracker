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
 * from the camera frame (0, 0) to the robot frame (0.5, 0.5)
 * 
 */
TEST(Obstacle_Test, position_in_robot_frame) {
    std::vector<std::vector<double> > transformation_matrix{
          {0.0, 0.0, -1.0, 0.5},
          {-1.0, 0.0, 0.0, 0.0},
          {0.0, -1.0, 0.0, 0.5},
          {0.0, 0.0, 0.0, 1.0}};

    Obstacle pos_test_obstacle;
    std::vector<double> expected_pos{0.5, 0.0};  // (x, y)
    std::vector<double> pos = pos_test_obstacle.GetRobotFrameCoordinates(
        transformation_matrix);

    for (int i = 0; i < pos.size(); i++) {
        EXPECT_DOUBLE_EQ(expected_pos[i], pos[i]);
    }
}

/**
 * @brief Test the transformation for the obstacle position 
 * from a bounding box (height, width) to the robot frame (x, y)
 * 
 */
TEST(Obstacle_test, camera_depth_pos) {
    std::vector<std::vector<double> > transformation_matrix{
        {0.0, 0.0, -1.0, 0.5},
        {-1.0, 0.0, 0.0, 0.0},
        {0.0, -1.0, 0.0, 0.5},
        {0.0, 0.0, 0.0, 1.0}};

    float focal_length{0.00367};  // Meters
    float horizontal_fov{1.2290609};  // Radians

    std::vector<std::vector<float>> positions{  // Expected positions in Meters
        {1.27, 0},
        {1.27, 0.635},
        {1.27, -0.635},
        {2.54, -0.635}};

    // (height, width) in pixels
    std::vector<std::vector<float>> bounding_boxes{
        {1312, 1260},
        {1307, 655},
        {1293, 615},
        {1005, 360}};

    for (int i = 0; i < positions.size(); i++) {
        std::vector<float> expected_pos = positions[i];
        std::vector<float> box = bounding_boxes[i];

        Obstacle pos_test_obstacle;

        pos_test_obstacle.SetObstacleHeight(box[0]);
        pos_test_obstacle.SetObstacleWidth(box[1]);
        pos_test_obstacle.ComputeDepth(focal_length);
        pos_test_obstacle.ComputeHorizontalPosition(horizontal_fov);

        std::vector<double> pos = pos_test_obstacle.GetRobotFrameCoordinates(
            transformation_matrix);

        for (int j = 0; j < pos.size(); j++) {
            EXPECT_NEAR(expected_pos[j], pos[j], 20);
        }
    }
}
