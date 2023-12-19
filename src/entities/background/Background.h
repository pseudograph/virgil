//
// Created by signal on 12/4/23.
//
#pragma once

#include "raylib.h"
#include "interfaces/Drawable.h"
#include "interfaces/Entity.h"
#include "interfaces/ImageTexture.h"

class Visitor;

class Background final : public Entity, public ImageTexture, public Drawable {
private:
    Image image{};
    Texture2D texture{};
    Color tint;
public:
    explicit Background(const std::string& fileName, const Color tint)
    : tint{tint} {
        image = LoadImage(fileName.c_str());
        texture = LoadTextureFromImage(image);
    }
    void draw() const override;
    void loadImage(const std::string& fileName) override;
    void updateTexture() override;
    void accept(Visitor& visitor) override;
};
