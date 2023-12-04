//
// Created by signal on 12/2/23.
//

#include "Screen.h"

#include "entities/visitors/drawVisitor/DrawVisitor.h"


void Screen::draw() const {
    DrawVisitor visitor;
    for (const auto& layer : layers) {
        for (const auto& entity : layer) {
            entity->accept(visitor);
        }
    }
}

void Screen::setChildrenWidth(float width) {
    for (const auto& layer : layers) {
        for (const auto& element : layer) {
        }
    }
}

void Screen::setChildrenHeight(float height) {
}

void Screen::scaleChildrenWidth(float multiplier) {
}

void Screen::scaleChildrenHeight(float multiplier) {
}

void Screen::scaleChildrenBoth(float multiplier) {
}
