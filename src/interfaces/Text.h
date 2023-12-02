//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>

class Text {
public:
    virtual ~Text() = default;
    virtual void setText(const std::string& text) = 0;
    [[nodiscard]] virtual std::string getText() const = 0;
    virtual void setWordWrap(bool wordWrap) = 0;
};
