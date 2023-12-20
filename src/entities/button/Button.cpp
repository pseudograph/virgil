//
// Created by signal on 12/20/23.
//

#include "Button.h"

#include "entities/visitors/Visitor.h"

void Button::click() {
    state = BUTTONDOWN;
}

void Button::draw() const {
    DrawTextureEx(textures[state], {bounds.x, bounds.y}, angle, 1.0, tint);
}

void Button::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Button::hover() {
    state = HOVER;
}

void Button::setX(const float x) {
    bounds.x = x;
}

void Button::setY(const float y) {
    bounds.y = y;
}

void Button::setXY(const float x, const float y) {
    bounds.x = x;
    bounds.y = y;
}

void Button::scaleXY(const float xMultiplier, const float yMultiplier) {
    bounds.x *= xMultiplier;
    bounds.y *= yMultiplier;
}

void Button::setWidth(const float width) {
    bounds.width = width;
}

void Button::setHeight(const float height) {
    bounds.height = height;
}

void Button::scaleWH(const float widthMultiplier, const float heightMultiplier) {
    bounds.width *= widthMultiplier;
    bounds.height *= heightMultiplier;
}

void Button::setRotation(const float angle) {
    this->angle = angle;
}
