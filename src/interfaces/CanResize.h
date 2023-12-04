//
// Created by signal on 12/2/23.
//
#pragma once

class CanResize {
public:
    virtual ~CanResize() = default;
    virtual void scaleChildren(float widthMultiplier, float heightMultiplier) = 0;
};
