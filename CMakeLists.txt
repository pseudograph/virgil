cmake_minimum_required(VERSION 3.27)
project(virgil)

set(CMAKE_CXX_STANDARD 23)
include_directories("${CMAKE_SOURCE_DIR}/src/")

add_executable(virgil src/main.cpp
        src/text/TextBlock.cpp
        src/text/TextBlock.h
        src/config/Consts.h
        src/interfaces/Drawable.h
        src/interfaces/Text.h
        src/interfaces/Repositionable.h
        src/interfaces/Resizable.h
)

