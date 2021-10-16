/** Copyright 2021
 *  @Authors
 *  Shon Cortes & Sameer Pusegaonkar
*/

#include <iostream>
#include "../include/camera.h"
#include "../include/detector.h"
#include "../include/obstacle.h"

int main() {
    auto d = new Detector();
    // std::string file_name = "../model_files/MobileNetSSD_deploy";
    // d->LoadModel(file_name);
    d->Detect();
    return 0;
}
