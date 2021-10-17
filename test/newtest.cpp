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


#include <../include/detector.h>

TEST(Detector_Test, test_the_bounding_boxes) {
  auto d = new Detector();
  std::ifstream ifs("../test/annotation.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj);  // reader can also read strings

  const Json::Value& detections = obj["detections"];
  for ( auto detection : detections ) {
    std::string file_name = "../test/Images/" + detection["ID"].asString() + ".jpg";

    std::ifstream infile(file_name);
    if (!infile) continue;

    cv::Mat image = cv::imread(file_name);
    std::cout << file_name << " " << std::endl;
    // cv::imshow("test", image);

    auto result = d->GetBoundingBoxes(image);
    std::cout << "---" <<std::endl;
    for ( auto cord : result ) {
      for (auto el : cord) {
        std::cout << el <<" ";
      }
      std::cout << " "<< std::endl;
    }

    std::vector<std::vector<int>> expected_value;
    for ( auto boxes : detection["gtboxes"] ) {
      // std::cout << " " << boxes["fbox"] << std::endl;
      std::vector<int> coordinates;
      coordinates.push_back(boxes["fbox"][0].asUInt());
      coordinates.push_back(boxes["fbox"][1].asUInt());
      coordinates.push_back(boxes["fbox"][2].asUInt());
      coordinates.push_back(boxes["fbox"][3].asUInt());
      expected_value.push_back(coordinates);
    }
    for ( auto cord : expected_value ) {
      for (auto el : cord) {
        std::cout << el <<" ";
      }
      std::cout << " "<< std::endl;
    }

    EXPECT_EQ(expected_value, result);
    // std::cout << " " << std::endl;
  }
}
