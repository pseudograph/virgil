//
// Created by signal on 12/2/23.
//
#pragma once

#include <string>
#include <utility>
#include <raylib.h>
#include "interfaces/Drawable.h"
#include "interfaces/Repositionable.h"
#include "interfaces/Resizable.h"
#include "interfaces/Text.h"


class TextBlock final : public Drawable, public Text, public Repositionable, public Resizable {
private:
    float x{};
    float y{};
    float width{};
    float height{};
    std::string text{};
    Font font;
    Color tint;
    float fontSize;
    float spacing;
    bool wordWrap{};
public:
    TextBlock(const float width, const float height, std::string text, const Font& font,
              const Color tint, const float fontSize, const float spacing, const bool wordWrap)
              :
              width{width}, height{height}, text{std::move(text)},
              font{font}, tint{tint}, fontSize{fontSize}, spacing{spacing}, wordWrap{wordWrap}
    {}
    // Drawable
    void Draw() override;
    // Text
    void SetText(const std::string& text) override;
    std::string GetText() override;
    void SetWordWrap(bool wordWrap) override;
    void DrawTextBox(const Font& font, const char *text, Rectangle rec, float fontSize, float spacing,
        bool wordWrap, Color tint);
    // Repositionable
    void setX(float x) override;
    void setY(float y) override;
    void setXY(float x, float y) override;
    // Resizable
    void setWidth(float width) override;
    void setHeight(float height) override;
    void scaleX(float multiplier) override;
    void scaleY(float multiplier) override;
    void scaleXY(float multiplier) override;
};
