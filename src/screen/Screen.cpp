//
// Created by signal on 12/2/23.
//

#include "Screen.h"

#include "entities/visitors/drawVisitor/DrawVisitor.h"
#include "entities/visitors/scaleWHVisitor/ScaleWHVisitor.h"


void Screen::draw() const {
    DrawVisitor visitor;
    visitAll(visitor);
}

void Screen::drawLayer(const size_t layer) const {
    DrawVisitor visitor;
    visitAllInLayer(visitor, layer);
}

void Screen::scaleChildren(const float widthMultiplier, const float heightMultiplier) {
    ScaleWHVisitor visitor{widthMultiplier, heightMultiplier};
    visitAll(visitor);
}

void Screen::visitAll(Visitor& visitor) const {
    for (const auto& layer : layers) {
        for (const auto& entity : layer) {
            entity->accept(visitor);
        }
    }
}

void Screen::visitAllInLayer(Visitor& visitor, const size_t layer) const {
    for (const auto& entity : layers[layer]) {
        entity->accept(visitor);
    }
}

void Screen::setLayerCount(const size_t layerCount) {
    while (layers.size() < layerCount) {
        layers.emplace_back();
    }
}

void Screen::insertEntity(const size_t layer, std::shared_ptr<Entity> entity) {
    layers[layer].push_back(std::move(entity));
}
