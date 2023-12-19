//
// Created by signal on 12/4/23.
//

#include "Background.h"

#include <iostream>

#include "entities/visitors/Visitor.h"

void Background::draw() const {
    DrawTexture(texture, 0, 0, WHITE);
}

void Background::loadImage(const std::string& fileName) {
    image = LoadImage(fileName.c_str());
}

void Background::updateTexture() {
    texture = LoadTextureFromImage(image);
}

void Background::accept(Visitor& visitor) {
    visitor.visit(*this);
}

