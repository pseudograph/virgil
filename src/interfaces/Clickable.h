//
// Created by signal on 12/20/23.
//

#pragma once

class Clickable {
public:
    virtual ~Clickable() = default;
    virtual void click() = 0;
};