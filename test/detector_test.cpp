/**
 * @file detector_test.cpp
 * @author Sameer Pusegaonkar & Shon Cortes
 * @brief Unit tests the detector class methods
 * @version 0.1
 * @date 2021-10-16
 * @copyright Copyright (c) 2021
 */

#include "../include/detector.h"

#include <gtest/gtest.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>


TEST(Detector_Test, test_the_bounding_boxes) {
  auto d = new Detector();
  d->LoadModel("../model_files/MobileNetSSD_deploy");
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

    // Checks if the image file is present or not
    std::ifstream infile(file_name);
    if (!infile) continue;

    // Get the count of the actual bounding boxes
    cv::Mat image = cv::imread(file_name);
    std::cout << file_name << " " << std::endl;
    auto result = d->GetBoundingBoxes(image);
    current_count += result.size();

    // Get the count of the ground truth bounding boxes
    for ( auto boxes : detection["gtboxes"] ) {
      ground_truth_count += boxes["fbox"].size();
    }
  }

  double percentage = current_count / ground_truth_count;
  EXPECT_GE(percentage , 0.0);
}

/**
 * @brief Construct a new TEST object to test if model loads successfully
 * 
 */
TEST(Detector_Test, test_loading_model) {
  Detector d;
  EXPECT_TRUE(d.LoadModel("../model_files/MobileNetSSD_deploy"));
  EXPECT_FALSE(d.LoadModel("Testing"));
}

TEST(Detector_Test, test_define_objects) {
  Detector d;
  std::vector<std::vector<int>> coordinates{
    {1, 2, 3, 4},
    {2, 3, 5, 6},
    {3, 4, 7, 8}};
  EXPECT_EQ(d.DefineObstacles(coordinates).size(), coordinates.size());
}


TEST(Detector_Test, test_detect_method) {
  auto d = new Detector();
  d->LoadModel("../model_files/MobileNetSSD_deploy");
  std::ifstream ifs("../test/test_annotation.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj);

  const Json::Value& detections = obj["detections"];
  for ( auto detection : detections ) {
    std::string file_name = "../test/Images/" + detection["ID"].asString() +
    ".jpg";

    // Checks if the image file is present or not
    std::ifstream infile(file_name);
    if (!infile) continue;

    // Get the count of the actual bounding boxes
    cv::Mat image = cv::imread(file_name);
    std::cout << file_name << " " << std::endl;

    int ground_truth_count = 0;
    for ( auto boxes : detection["gtboxes"] ) {
      ground_truth_count += boxes["fbox"].size();
    }

    auto result = d->Detect(image);
    EXPECT_NEAR(result.size(), ground_truth_count, 200);
  }
}
