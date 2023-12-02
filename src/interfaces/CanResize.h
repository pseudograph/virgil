//
// Created by signal on 12/2/23.
//
#pragma once

class CanResize {
public:
    virtual ~CanResize() = default;
    virtual void setChildrenWidth(float width) = 0;
    virtual void setChildrenHeight(float height) = 0;
    virtual void scaleChildrenWidth(float multiplier) = 0;
    virtual void scaleChildrenHeight(float multiplier) = 0;
    virtual void scaleChildrenBoth(float multiplier) = 0;
};
