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
  std::unique_ptr<Detector> d = std::make_unique<Detector>();
  const std::string file_name = "../model_files/MobileNetSSD_deploy";
  d->LoadModel(file_name);

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
    std::cout << "---\n";
    for ( auto robot_coordinate : robot_coordinates ) {
      std::cout << "(" << robot_coordinate[0] << ", "
        << robot_coordinate[1] << ") ";
    }

    std::cout << "\n---\n";
    cv::imshow("Video feed from Medibot", img);

    int k = cv::waitKey(10);
    if (k == 113) {
        break;
    }
  }
  cap.release();
  cv::destroyAllWindows();
}
