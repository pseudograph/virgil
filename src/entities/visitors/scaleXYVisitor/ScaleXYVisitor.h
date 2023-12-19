//
// Created by signal on 12/3/23.
//
#pragma once
#include "entities/visitors/Visitor.h"


class ScaleXYVisitor final : public Visitor {
private:
    float scaleXBy;
    float scaleYBy;
public:
    ScaleXYVisitor(const float scaleXBy, const float scaleYBy) : scaleXBy{scaleXBy}, scaleYBy{scaleYBy}
    {}
    void visit(TextBlock& textblock) override;
    void visit(Background& background) override;
    void visit(Sprite& sprite) override;
};
