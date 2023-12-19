//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>
#include <utility>
#include <raylib.h>
#include <fmt/core.h>

#include "config/Config.h"
#include "screen/Screen.h"


class Viewport {
private:
    Rectangle src;
    Rectangle dest;
    RenderTexture2D target{};
    Vector2 origin{};
    int fps;
    std::string title;
    std::vector<Screen> screens;
    size_t activeScreen;
    void Init() {
        InitWindow(static_cast<int>(dest.width), static_cast<int>(dest.height), title.c_str());
        SetTargetFPS(fps);
        target = LoadRenderTexture(static_cast<int>(src.width), static_cast<int>(-1 * src.height));
    }

public:
    Viewport(const int width, const int height, const int fps, std::string title, const size_t activeScreen = 0) :
             // src{0, HEIGHT, WIDTH, -HEIGHT} to account for OpenGL coordinate discrepancy (origin at bottom-left)
             src{0, BASE_HEIGHT, BASE_WIDTH, -1 * BASE_HEIGHT},
             dest{0, 0, static_cast<float>(width), static_cast<float>(height)},
             origin{0, 0}, fps{fps}, title{std::move(title)}, activeScreen{activeScreen} {
        Init();
    }

    void run();
    void resizeMaintainingAspectRatio(int width, int height);
    void setWidth(int width);
    void setHeight(int height);
    void scaleWH(float widthMultiplier, float heightMultiplier);
    void insertScreen(const Screen& screen);
};
