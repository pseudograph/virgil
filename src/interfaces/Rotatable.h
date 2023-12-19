//
// Created by signal on 12/19/23.
//

#pragma once

class Rotatable {
public:
    virtual ~Rotatable() = default;
    virtual void setRotation(float angle) = 0;
};