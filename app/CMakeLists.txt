add_executable(shell-app main.cpp obstacle.cpp camera.cpp detector.cpp)

# Link OpenCV
target_link_libraries( shell-app ${OpenCV_LIBS} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
    $ENV{EIGEN3_INCLUDE_DIR}
)
