cmake_minimum_required(VERSION 3.2.1)
project (scratch)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# Import opencv 
find_package(OpenCV REQUIRED)
#include opencv directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Display opencv include directory
message( [opencv] ${OpenCV_INCLUDE_DIRS} )
message( [opencv] ${${OpenCV_LIBS}} )
message( [opencv] ${${OpenCV_LIBRARIES}} )

# Include Eigen
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
INCLUDE_DIRECTORIES($ENV{EIGEN3_INCLUDE_DIR})

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})
#add_executable(myprogram myprogram.cpp)
#target_link_libraries(myprogram ${JSONCPP_LIBRARIES})


# We probably don't want this to run on every build.
option(COVERAGE "Generate Coverage Data" OFF)

if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'vendor/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS app/main.cpp app/obstacle.cpp app/camera.cpp app/detector.cpp include/camera.h include/obstacle.h include/detector.h)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)