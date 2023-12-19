//
// Created by signal on 12/3/23.
//
#pragma once

#include "entities/background/Background.h"
#include "entities/sprite/Sprite.h"
#include "entities/text/TextBlock.h"

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(TextBlock& textblock) = 0;
    virtual void visit(Background& background) = 0;
    virtual void visit(Sprite& sprite) = 0;
};
