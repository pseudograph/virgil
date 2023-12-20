//
// Created by signal on 12/20/23.
//

#pragma once

class Hoverable {
public:
    virtual ~Hoverable() = default;
    virtual void hover() = 0;
};