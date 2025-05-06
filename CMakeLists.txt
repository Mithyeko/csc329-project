cmake_minimum_required(VERSION 3.29)
project(project326)

set(CMAKE_CXX_STANDARD 20)

add_executable(project326 main.cpp
        sort.cpp
        SortMetrics.h
        sort.h
        metrics.cpp
        FisherYates.cpp
        FisherYates.h)
