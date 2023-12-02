//
// Created by signal on 12/2/23.
//
#pragma once

#include "entities/visitors/Visitor.h"


class DrawingVisitor final : public Visitor {
public:
    void visit(TextBlock& button) override;
};
