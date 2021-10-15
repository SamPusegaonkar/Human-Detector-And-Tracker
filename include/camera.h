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
  friend class Detector;
  ~Camera() {}
};
