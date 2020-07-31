cmake_minimum_required( VERSION 2.8 )
project( mathCalc )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )


add_executable( calc_correlation calcCorrelation.cpp )
add_executable( calc_percentile calcPercentile.cpp)