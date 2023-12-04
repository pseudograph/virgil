//
// Created by signal on 12/2/23.
//
#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "interfaces/CanResize.h"
#include "interfaces/Drawable.h"
#include "interfaces/Entity.h"


class Screen final : public Drawable, public CanResize {
private:
    std::string label;
    std::vector<std::vector<std::shared_ptr<Entity>>> layers;
public:
    explicit Screen(std::string label) : label{std::move(label)}
    {}
    Screen(const Screen& other) {
        label = other.label;
        layers = std::vector<std::vector<std::shared_ptr<Entity>>>{};
        for (size_t layer{0}; layer < other.layers.size(); ++layer) {
            layers.emplace_back();
            for (auto& entityPtr : other.layers[layer]) {
                layers[layer].push_back(entityPtr);
            }
        }
    }
    void draw() const override;
    void drawLayer(size_t layer) const;
    void scaleChildren(float widthMultiplier, float heightMultiplier) override;
    void visitAll(Visitor& visitor) const;
    void visitAllInLayer(Visitor& visitor, size_t layer) const;
    void setLayerCount(size_t layerCount);
    void insertEntity(size_t layer, std::shared_ptr<Entity> entity);
};
