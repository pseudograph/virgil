//
// Created by signal on 12/4/23.
//

#include "Background.h"

#include <iostream>

#include "entities/visitors/Visitor.h"

void Background::draw() const {
    DrawTexture(texture, x, y, WHITE);
}

void Background::loadImage(const std::string& fileName) {
    image = LoadImage(fileName.c_str());
}

void Background::updateTexture() {
    texture = LoadTextureFromImage(image);
}

void Background::setX(const float x) {
    this->x = x;
}

void Background::setY(const float y) {
    this->y = y;
}

void Background::setXY(const float x, const float y) {
    setX(x);
    setY(y);
}

void Background::scaleXY(const float xMultiplier, const float yMultiplier) {
    x *= xMultiplier;
    y *= yMultiplier;
}

void Background::setWidth(const float width) {
    this->width = width;
}

void Background::setHeight(const float height) {
    this->height = height;
}

void Background::scaleWH(const float widthMultiplier, const float heightMultiplier) {
    width *= widthMultiplier;
    height *= heightMultiplier;
}

void Background::accept(Visitor& visitor) {
    visitor.visit(*this);
}

