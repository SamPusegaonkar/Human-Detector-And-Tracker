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
