//
// Created by signal on 12/2/23.
//

#include "Viewport.h"
#include <fmt/format.h>
#include "config/Consts.h"

#include <iostream>


void Viewport::run() const {
    while (!WindowShouldClose()) {
        Rectangle src{0, 0, 1920, 1080};
        Rectangle dest{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
        RenderTexture2D target = LoadRenderTexture(1920, 1080);
        if (screens.empty()) {
            fmt::println(stderr, "[Viewport:run]: No screens defined.");
        }
        BeginTextureMode(target);
            ClearBackground(RED);
            for (const Screen& screen : screens) {
                screen.draw();
            }
        EndTextureMode();
        BeginDrawing();
            DrawTexturePro(target.texture, src, dest, {0, 0}, 0.0, RAYWHITE);
        EndDrawing();
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
