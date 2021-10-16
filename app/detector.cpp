/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#include <iostream>
#include "../include/detector.h"

// TO DO: Add detailed info on class method.
/**
 * @brief Load the human detection model.
 * 
 * @param file_name 
 * @return true 
 * @return false 
 */
bool Detector::LoadModel(std::string file_name) {}

// TO DO: Add detailed info on class method.
/**
 * @brief Process video feed and call the necessary functions to detect and track obstacles 
 * while returning their position in the robot frame.
 * 
 */
void Detector::Detect() {}

// TO DO: Add detailed info on class method.
/**
 * @brief Return a vector containing all detected obstacles.
 * 
 * @param frame Video frame being processed.
 * @return std::vector<int> Vector containing all detected obstacles.
 */
std::vector<int> Detector::GetBoundingBoxes(cv::Mat frame) {}

// TO DO: Add detailed info on class method.
/**
 * @brief Creates an Obstacle instance for each obstacle detected.
 * 
 * @param coordinates Bounding box coordinates to be used in 
 * calculating the obstacle position in the Camera frame.
 * @return std::vector<Obstacle> A vector of Obstacle instances.
 */
std::vector<Obstacle> Detector::DefineObstacles(std::vector<int> coordinates) {}

// TO DO: Add detailed info on class method.
/**
 * @brief Writes the Obstacles coordinates, with respect to the 
 * robot coordinate frame, on the frame. 
 * 
 * @param frame Video frame being processed.
 * @return cv::Mat Video frame with coordinates displayed.
 */
cv::Mat Detector::WriteRobotCoordinatesOnFrame(std::vector<Obstacle>,
    cv::Mat frame) {}
