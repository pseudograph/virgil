//
// Created by signal on 12/19/23.
//

#pragma once


#include <string>

#include "raylib.h"
#include "interfaces/Drawable.h"
#include "interfaces/Entity.h"
#include "interfaces/Repositionable.h"
#include "interfaces/Resizable.h"
#include "interfaces/Rotatable.h"


class Visitor;

class Sprite final : public Entity, public Drawable, public Resizable, public Repositionable, public Rotatable {
private:
    float x;
    float y;
    float width;
    float height;
    float angle;
    Color tint;
    Image image{};
    Texture2D texture{};
public:
    Sprite(const std::string& fileName, const Color tint, const float x, const float y, const float width, const float height, const float angle)
        : x{x}, y{y}, width{width}, height{height}, angle{angle}, tint{tint} {
        image = LoadImage(fileName.c_str());
        texture = LoadTextureFromImage(image);
    }

    void draw() const override;
    void accept(Visitor& visitor) override;
    void setX(float x) override;
    void setY(float y) override;
    void setXY(float x, float y) override;
    void scaleXY(float xMultiplier, float yMultiplier) override;
    void setWidth(float width) override;
    void setHeight(float height) override;
    void scaleWH(float widthMultiplier, float heightMultiplier) override;
    void setRotation(float angle) override;
};
