//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>
#include <utility>
#include <raylib.h>
#include <fmt/core.h>

#include "config/Consts.h"
#include "screen/Screen.h"


class Viewport {
private:
    Rectangle src;
    Rectangle dest;
    int fps;
    std::string title;
    std::vector<Screen> screens;
    size_t activeScreen;
    void Init() const {
        InitWindow(static_cast<int>(dest.width), static_cast<int>(dest.height), title.c_str());
        SetTargetFPS(fps);
    }

public:
    Viewport(const int width, const int height, const int fps, std::string title, const size_t activeScreen = 0) :
             src{0, 0, BASE_WIDTH, BASE_HEIGHT}, dest{0, 0, static_cast<float>(width), static_cast<float>(height)},
             fps{fps}, title{std::move(title)}, activeScreen{activeScreen} {
        Init();
    }
    void run() const;
    void setWidth(int width);
    void setHeight(int height);
    void scaleWH(float widthMultiplier, float heightMultiplier);
    void insertScreen(const Screen& screen);
};
