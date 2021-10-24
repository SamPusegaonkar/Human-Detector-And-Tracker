/**
 * @file camera.h
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Camera class used to store camera parameters
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <vector>

/**
 * @brief A class to define all camera paramters.
 */
class Camera {
 private:
  int fps_;
  float horizontal_fov_;
  float focal_length_;
  std::vector<std::vector<double> > transformation_matrix_;

 public:
  /**
   * @brief Construct a new Camera object & fill it with camera parameters
   */
  Camera() :
// Transformation matrix to go from camera to robot frame
  transformation_matrix_ {
          {{0.0, 0.0, -1.0, 0.5},
          {-1.0, 0.0, 0.0, 0.0},
          {0.0, -1.0, 0.0, 0.5},
          {0.0, 0.0, 0.0, 1.0}}}  // Meters
  {
  this->fps_ = 30;
  this->horizontal_fov_ = 1.2290609;  // Radians
  this->focal_length_ = 0.00367f;  // Meters
  }
  friend class Detector;
  ~Camera() {}
};
