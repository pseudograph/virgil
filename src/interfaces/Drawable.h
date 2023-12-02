//
// Created by signal on 12/2/23.
//
#pragma once

#include "entities/visitors/Visitor.h"

class Visitor;

class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void draw() const = 0;
    virtual void accept(Visitor& visitor) = 0;
};
