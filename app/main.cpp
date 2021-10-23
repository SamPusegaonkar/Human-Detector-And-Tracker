/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#include <iostream>
#include "../include/camera.h"
#include "../include/detector.h"
#include "../include/obstacle.h"
#include <fstream>
#include <jsoncpp/json/json.h>


int main() {
  auto d = new Detector();
  // d->LoadModel();

  cv::VideoCapture cap;
  cap.open(0);
  if (!cap.isOpened()) {
    std::cout << "CANNOT OPEN CAM" << std::endl;
    return 1;
  }
  cv::Mat img;
  while (true) {
    cap >> img;
    auto detections = d->Detect(img);
    for ( auto detection : detections ) {
      for ( auto coordiante : detection ) {
        std::cout << coordiante << std::endl;
      }
    }
    cv::imshow("Video Feed from MediBot", img);
    int k = cv::waitKey(10);
    if (k == 113) {
        break;
    }
  }
  cap.release();
  cv::destroyAllWindows();
}
