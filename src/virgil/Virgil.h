//
// Created by signal on 12/2/23.
//
#pragma once


#include "viewport/Viewport.h"
#include "config/Consts.h"

class Virgil {
public:
    Viewport viewport;
    Virgil() : viewport{SCREEN_WIDTH, SCREEN_HEIGHT, FPS, TITLE}
    {}
    void run() const;
};
