cmake_minimum_required(VERSION 3.27)
project(virgil)

set(CMAKE_CXX_STANDARD 23)

add_executable(virgil src/main.cpp
        src/text/TextBlock.cpp
        src/text/TextBlock.h
)
