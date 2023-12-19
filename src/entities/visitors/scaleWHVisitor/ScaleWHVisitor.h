//
// Created by signal on 12/3/23.
//
#pragma once

#include "entities/visitors/Visitor.h"


class ScaleWHVisitor final : public Visitor {
private:
    float scaleWidthBy;
    float scaleHeightBy;
public:
    ScaleWHVisitor(const float scaleWidthBy, const float scaleHeightBy) : scaleWidthBy{scaleWidthBy}, scaleHeightBy{scaleHeightBy}
    {}
    void visit(TextBlock& textblock) override;
    void visit(Background& background) override;
};
