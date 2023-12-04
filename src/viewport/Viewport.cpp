//
// Created by signal on 12/2/23.
//

#include "Viewport.h"
#include <fmt/format.h>

#include <iostream>

void Viewport::run() const {
    while (!WindowShouldClose()) {
        if (screens.empty()) {
            fmt::println(stderr, "[Viewport:run]: No screens defined.");
        }
        BeginDrawing();
        for (const Screen& screen : screens) {
            screen.draw();
        }
        EndDrawing();
    }
}

void Viewport::setWidth(const int width) {
    this->width = width;
}

void Viewport::setHeight(const int height) {
    this->height = height;
}

void Viewport::scaleWH(const int widthMultiplier, const int heightMultiplier) {
    width *= widthMultiplier;
    height *= heightMultiplier;
}

void Viewport::insertScreen(const Screen& screen) {
    screens.push_back(screen);
}
