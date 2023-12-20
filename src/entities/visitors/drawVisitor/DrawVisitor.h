//
// Created by signal on 12/3/23.
//
#pragma once

#include "entities/visitors/Visitor.h"


class DrawVisitor final : public Visitor {
public:
    void visit(TextBlock& textblock) override;
    void visit(Background& background) override;
    void visit(Sprite& sprite) override;
    void visit(Button& button) override;
};
