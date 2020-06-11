cmake_minimum_required(VERSION 3.16)
project(sht_sensor_lib)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sht_sensor_lib
        sht21.cpp
        sht21.h)
