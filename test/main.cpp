/**
 * @file main.cpp
 * @author Shon Cortes & Sameer Pusegaonkar
 * @brief Runs all unit tests
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
