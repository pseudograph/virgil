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
    std::vector<std::vector<std::unique_ptr<Entity>>> layers;
public:
    explicit Screen(std::string label) : label{std::move(label)}
    {}
    void draw() const override;
    void setChildrenWidth(float width) override;
    void setChildrenHeight(float height) override;
    void scaleChildrenWidth(float multiplier) override;
    void scaleChildrenHeight(float multiplier) override;
    void scaleChildrenBoth(float multiplier) override;
};
