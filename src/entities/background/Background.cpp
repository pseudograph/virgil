//
// Created by signal on 12/4/23.
//

#include "Background.h"

#include "entities/visitors/Visitor.h"

void Background::draw() const {
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

void Background::scaleX(const float multiplier) {
    x *= multiplier;
}

void Background::scaleY(const float multiplier) {
    y *= multiplier;
}

void Background::scaleXY(const float multiplier) {
    scaleX(multiplier);
    scaleY(multiplier);
}

void Background::setWidth(const float width) {
    this->width = width;
}

void Background::setHeight(const float height) {
    this->height = height;
}

void Background::scaleWidth(const float multiplier) {
    width *= multiplier;
}

void Background::scaleHeight(const float multiplier) {
    height *= multiplier;
}

void Background::scaleBoth(const float multiplier) {
    scaleWidth(multiplier);
    scaleHeight(multiplier);
}

void Background::accept(Visitor& visitor) {
    visitor.visit(*this);
}

