//
// Created by signal on 12/2/23.
//
#pragma once

#include "entities/text/TextBlock.h"
#include "screen/Screen.h"


class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(TextBlock& textBlock) = 0;
    virtual void visit(Screen& screen) = 0;
};
