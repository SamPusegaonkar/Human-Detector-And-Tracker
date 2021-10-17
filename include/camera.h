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
  std::vector<std::vector<int>> _transformation_matrix;

 public:
  Camera() {
  int fps_{0};
  float horizontal_fov_{0};
  float focal_length_{0};
  // TO DO: Create transformation matrix to go from Camera frame to Robot frame.
  std::vector<std::vector<int>> _transformation_matrix{0};
}

  ~Camera(){}
};
