//
// Created by signal on 12/2/23.
//
#pragma once
#include "entities/text/TextBlock.h"


class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(TextBlock& button) = 0;
};
