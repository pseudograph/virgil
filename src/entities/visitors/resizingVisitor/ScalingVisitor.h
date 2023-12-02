//
// Created by signal on 12/2/23.
//
#pragma once
#include "entities/visitors/Visitor.h"


class ScalingVisitor final : public Visitor {
private:
    float scaleXBy{1.0};
    float scaleYBy{1.0};
public:
    explicit ScalingVisitor(const float resizeXBy, const float resizeYBy) : scaleXBy{resizeXBy}, scaleYBy{resizeYBy}
    {}
    void visit(TextBlock& textBlock) override;
};
