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

class Camera {
 private:
  int fps_;
  float horizontal_fov_;
  float focal_length_;
  std::vector<std::vector<double> > transformation_matrix_;

 public:
  Camera() {
  int fps_{30};
  float horizontal_fov_{1.2290609};  // Radians
  float focal_length_{0.00367};  // Meters
  // Transformation matrix to go from camera to robot frame
  std::vector<std::vector<double> > transformation_matrix_{
          {0.0, 0.0, -1.0, 0.5},
          {-1.0, 0.0, 0.0, 0.0},
          {0.0, -1.0, 0.0, 0.5},
          {0.0, 0.0, 0.0, 1.0}};
  }  // Meters
  friend class Detector;
  ~Camera() {}
};
