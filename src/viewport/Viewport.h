//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>
#include <utility>
#include <raylib.h>
#include "interfaces/Resizable.h"


class Viewport : public Resizable {
private:
    int width;
    int height;
    int fps;
    std::string title;
    void Init() const {
        InitWindow(width, height, title.c_str());
        SetTargetFPS(fps);
    }
    void Run() {
        while (!WindowShouldClose()) {

        }
    }
public:
    Viewport(const int width, const int height, const int fps, std::string title) :
             width{width}, height{height}, fps{fps}, title{std::move(title)} {
        Init();
        Run();
    }
};
