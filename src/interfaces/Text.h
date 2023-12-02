//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>

class Text {
public:
    virtual ~Text() = default;
    virtual void SetText(const std::string& text) = 0;
    virtual std::string GetText() = 0;
    virtual void SetWordWrap(bool wordWrap) = 0;
};
