/**
 * @file detector_test.cpp
 * @author Sameer Pusegaonkar & Shon Cortes
 * @brief Unit tests the detector class methods
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <string>

#include "../include/detector.h"

TEST(Detector_Test, test_the_bounding_boxes) {
  auto d = new Detector();
  std::ifstream ifs("../test/test_annotation.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj);  

  double ground_truth_count = 0;
  double current_count = 0;

  const Json::Value& detections = obj["detections"];
  for ( auto detection : detections ) {
    std::string file_name = "../test/Images/" + detection["ID"].asString() +
    ".jpg";

    std::ifstream infile(file_name);
    if (!infile) continue;

    cv::Mat image = cv::imread(file_name);
    std::cout << file_name << " " << std::endl;
    auto result = d->GetBoundingBoxes(image);
    current_count += result.size();
    for ( auto boxes : detection["gtboxes"] ) {
      ground_truth_count += boxes["fbox"].size();
    }
  }

  double percentage = current_count / ground_truth_count;
  EXPECT_GE(percentage , 0.2);
}
