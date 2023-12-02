//
// Created by signal on 12/2/23.
//
#pragma once


class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void draw() const = 0;
};
