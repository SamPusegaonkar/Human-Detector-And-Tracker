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
  std::vector<std::vector<double> > transformation_matrix_;

 public:
  friend class Detector;
  ~Camera() {}
};
