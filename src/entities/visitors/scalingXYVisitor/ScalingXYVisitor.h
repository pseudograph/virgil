//
// Created by signal on 12/2/23.
//
#pragma once
#include "entities/visitors/Visitor.h"


class ScalingXYVisitor final : public Visitor {
private:
    float scaleXBy{1.0};
    float scaleYBy{1.0};
public:
    ScalingXYVisitor(const float scaleXBy, const float scaleYBy) : scaleXBy{scaleXBy}, scaleYBy{scaleYBy}
    {}
    void visit(TextBlock& textBlock) override;
};
