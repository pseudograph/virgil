//
// Created by signal on 12/2/23.
//
#pragma once
#include "entities/visitors/Visitor.h"


class ScalingWHVisitor final : public Visitor {
private:
    float scaleWidthBy{1.0};
    float scaleHeightBy{1.0};
public:
    ScalingWHVisitor(const float scaleWidthBy, const float scaleHeightBy) : scaleWidthBy{scaleWidthBy}, scaleHeightBy{scaleHeightBy}
    {}
    void visit(TextBlock& textBlock) override;
};
