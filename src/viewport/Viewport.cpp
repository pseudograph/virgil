//
// Created by signal on 12/2/23.
//

#include "Viewport.h"
#include <fmt/format.h>

#include <iostream>



void Viewport::run() {
    while (!WindowShouldClose()) {
        if (IsWindowResized()) {
            resizeMaintainingAspectRatio(GetScreenWidth(), GetScreenHeight());
        }
        if (screens.empty()) {
            fmt::println(stderr, "ERROR: [Viewport:run]: No screens defined.");
        }
        BeginTextureMode(target);
            ClearBackground(RAYWHITE);
            for (const Screen& screen : screens) {
                screen.draw();
            }
        EndTextureMode();
        BeginDrawing();
            DrawTexturePro(target.texture, src, dest, origin, 0, RAYWHITE);
        EndDrawing();
    }
}

void Viewport::resizeMaintainingAspectRatio(const int width, const int height) {
    if (height < width) {
        setHeight(height);
        setWidth(static_cast<int>(static_cast<float>(height) * (static_cast<float>(SCREEN_WIDTH) / static_cast<float>(SCREEN_HEIGHT))));
        origin.y = 0;
        origin.x = -1 * (static_cast<float>(width) - dest.width) / 2;
    } else {
        setWidth(width);
        setHeight(static_cast<int>(static_cast<float>(width) * (static_cast<float>(SCREEN_HEIGHT) / static_cast<float>(SCREEN_WIDTH))));
        origin.x = 0;
        origin.y = -1 * (static_cast<float>(height) - dest.height) / 2;
    }
}

void Viewport::setWidth(const int width) {
    dest.width = static_cast<float>(width);
}

void Viewport::setHeight(const int height) {
    dest.height = static_cast<float>(height);
}

void Viewport::scaleWH(const float widthMultiplier, const float heightMultiplier) {
    dest.width *= widthMultiplier;
    dest.height *= heightMultiplier;
}

void Viewport::insertScreen(const Screen& screen) {
    screens.push_back(screen);
}
