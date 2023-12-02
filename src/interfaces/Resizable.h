//
// Created by signal on 12/2/23.
//

#pragma once

class Resizable {
public:
    virtual ~Resizable() = default;
    virtual void setWidth(float width) = 0;
    virtual void setHeight(float height) = 0;
    virtual void scaleWidth(float multiplier) = 0;
    virtual void scaleHeight(float multiplier) = 0;
    virtual void scaleBoth(float multiplier) = 0;
};
