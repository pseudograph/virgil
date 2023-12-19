//
// Created by signal on 12/19/23.
//

#include "Sprite.h"

#include "entities/visitors/Visitor.h"

void Sprite::draw() const {
    DrawTextureEx(texture, {x, y}, angle, 1.0, tint);
}

void Sprite::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Sprite::setX(const float x) {
    this->x = x;
}

void Sprite::setY(const float y) {
    this->y = y;
}

void Sprite::setXY(const float x, const float y) {
    this->x = x;
    this->y = y;
}

void Sprite::scaleXY(const float xMultiplier, const float yMultiplier) {
    x *= xMultiplier;
    y *= yMultiplier;
}

void Sprite::setWidth(const float width) {
    this->width = width;
}

void Sprite::setHeight(const float height) {
    this->height = height;
}

void Sprite::scaleWH(const float widthMultiplier, const float heightMultiplier) {
    width *= widthMultiplier;
    height *= heightMultiplier;
}

void Sprite::setRotation(const float angle) {
    this->angle = angle;
}
