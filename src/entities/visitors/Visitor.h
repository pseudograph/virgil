//
// Created by signal on 12/3/23.
//
#pragma once

#include "entities/text/TextBlock.h"

class Visitor {
    virtual ~Visitor() = default;
    virtual void visit(TextBlock& textblock) = 0;
};
