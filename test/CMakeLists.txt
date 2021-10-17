set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    detector_test.cpp
    ../app/detector.cpp
    ${OpenCV_INCLUDE_DIRS}
    obstacle_test.cpp
    ../app/obstacle.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})

