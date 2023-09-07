cmake_minimum_required(VERSION 3.25)
project(viewer)

set(CMAKE_CXX_STANDARD 14)

include_directories(model)

add_executable(viewer
        model/affine.cpp
        model/affine.h
        model/parser.cpp
        model/parser.h model/model.h)
