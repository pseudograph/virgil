//
// Created by signal on 12/4/23.
//
#pragma once

#include <string>


class ImageTexture {
public:
    virtual ~ImageTexture() = default;
    virtual void loadImage(const std::string& fileName) = 0;
    virtual void updateTexture() = 0;
};
