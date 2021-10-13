/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#pragma once

#include <iostream>
#include <vector>

class Camera {
 private:
  int fps_;
  float horizontal_fov_;
  float focal_length_;
  std::vector<std::vector<double> > _transformation_matrix;

 public:
  friend class Detector;
  ~Camera() {}
};
