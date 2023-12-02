//
// Created by signal on 12/3/23.
//
#pragma once
#include "entities/visitors/Visitor.h"


class DrawVisitor final : public Visitor {
    void visit(TextBlock& textblock) override;
};
