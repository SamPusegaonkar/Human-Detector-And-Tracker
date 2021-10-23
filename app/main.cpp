/**
 * @file main.cpp
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Main file to implament 
 * @version 0.1
 * @date 2021-10-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>

#include "../include/camera.h"
#include "../include/detector.h"
#include "../include/obstacle.h"

int main() {
  auto d = new Detector();
  d->LoadModel("../model_files/MobileNetSSD_deploy");

  cv::VideoCapture cap;
  cap.open(0);
  if (!cap.isOpened()) {
      std::cout << "CANNOT OPEN CAM" << std::endl;
      return 1;
  }
  cv::Mat img;
  while (true) {
    cap >> img;
    auto robot_coordinates = d->Detect(img);

    for ( auto robot_coordinate : robot_coordinates ) {
      for ( auto coordiante : robot_coordinate ) {
        std::cout << coordiante << std::endl;
      }
    }

    auto frame = d->WriteRobotCoordinatesOnFrame(img);

    int k = cv::waitKey(10);
    if (k == 113) {
        break;
    }
  }
  cap.release();
  cv::destroyAllWindows();
}
