//
// Created by signal on 12/20/23.
//

#pragma once
#include <string>
#include <vector>

#include "raylib.h"
#include "interfaces/Clickable.h"
#include "interfaces/Drawable.h"
#include "interfaces/Entity.h"
#include "interfaces/Hoverable.h"
#include "interfaces/Repositionable.h"
#include "interfaces/Resizable.h"
#include "interfaces/Rotatable.h"


class Button final : public Entity, public Drawable, public Repositionable, public Resizable, public Rotatable, public Hoverable,
                     public Clickable {
private:
    enum STATE {
        BUTTONUP,
        HOVER,
        BUTTONDOWN
    };
    Rectangle bounds;
    float angle;
    STATE state{BUTTONUP};
    std::vector<Image> images;
    std::vector<Texture2D> textures;
    Color tint;
public:
    Button(const std::vector<std::string>& fileNames, const float x, const float y, const float width, const float height,
        const float angle, const Color tint)
    : bounds{x, y, width, height}, angle{angle}, tint{tint} {
        for (const auto& fileName : fileNames) {
            Image image{LoadImage(fileName.c_str())};
            images.push_back(image);
            textures.push_back(LoadTextureFromImage(image));
        }
    }
    void click() override;
    void draw() const override;
    void accept(Visitor& visitor) override;
    void hover() override;
    void setX(float x) override;
    void setY(float y) override;
    void setXY(float x, float y) override;
    void scaleXY(float xMultiplier, float yMultiplier) override;
    void setWidth(float width) override;
    void setHeight(float height) override;
    void scaleWH(float widthMultiplier, float heightMultiplier) override;
    void setRotation(float angle) override;
};
