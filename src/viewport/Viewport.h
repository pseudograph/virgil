//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>
#include <utility>
#include <raylib.h>
#include "screen/Screen.h"


class Viewport {
private:
    int width;
    int height;
    int fps;
    std::string title;
    std::vector<Screen> screens;
    size_t activeScreen{0};
    void Init() const {
        InitWindow(width, height, title.c_str());
        SetTargetFPS(fps);
    }

public:
    Viewport(const int width, const int height, const int fps, std::string title) :
             width{width}, height{height}, fps{fps}, title{std::move(title)} {
        Init();
    }
    void run() const;
    void setWidth(int width);
    void setHeight(int height);
    void scaleWH(int widthMultiplier, int heightMultiplier);
    void insertScreen(const Screen& screen);
};
