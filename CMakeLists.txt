cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
set (CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
add_executable( DisplayImage main.cpp camera.h)
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
include_directories(/home/ric92/openCVTest/openCVtest/first/openCVtest)

