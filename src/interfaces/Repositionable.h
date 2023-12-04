//
// Created by signal on 12/2/23.
//

#pragma once

class Repositionable {
public:
    virtual ~Repositionable() = default;
    virtual void setX(float x) = 0;
    virtual void setY(float y) = 0;
    virtual void setXY(float x, float y) = 0;
    virtual void scaleXY(float xMultiplier, float yMultiplier) = 0;
};
