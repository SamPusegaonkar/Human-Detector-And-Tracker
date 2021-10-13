/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#include "../include/camera.h"
#include <iostream>
#include <vector>

// TO DO: Define actual initialization values
/**
 * @brief Construct a new Camera:: Camera object
 * 
 */
Camera::Camera() {
  int fps_{0};
  float horizontal_fov_{0};
  float focal_length_{0};
  // Transformation matrix to go from camera to robot frame
  std::vector<std::vector<double> > _transformation_matrix{
          {0.0, 0.0, -1.0, 0.5},
          {-1.0, 0.0, 0.0, 0.0},
          {0.0, -1.0, 0.0, 0.5},
          {0.0, 0.0, 0.0, 1.0}};
  }
