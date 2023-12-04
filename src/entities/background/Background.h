//
// Created by signal on 12/4/23.
//
#pragma once

#include "raylib.h"
#include "interfaces/Drawable.h"
#include "interfaces/Entity.h"
#include "interfaces/ImageTexture.h"
#include "interfaces/Repositionable.h"
#include "interfaces/Resizable.h"

class Visitor;

class Background final : public Entity, public ImageTexture, public Drawable, public Repositionable, public Resizable {
private:
    float x;
    float y;
    float width;
    float height;
    Image image{};
    Texture2D texture{};
    Color tint;
public:
    explicit Background(const std::string& fileName, const float x, const float y, const float width, const float height,
                        const Color tint)
    :
    x{x}, y{y}, width{width}, height{height}, tint{tint}
    {
        image = LoadImage(fileName.c_str());
        texture = LoadTextureFromImage(image);
    }
    void draw() const override;
    void loadImage(const std::string& fileName) override;
    void updateTexture() override;
    void setX(float x) override;
    void setY(float y) override;
    void setXY(float x, float y) override;
    void scaleXY(float xMultiplier, float yMultiplier) override;
    void setWidth(float width) override;
    void setHeight(float height) override;
    void scaleWH(float widthMultiplier, float heightMultiplier) override;
    void accept(Visitor& visitor) override;
};
