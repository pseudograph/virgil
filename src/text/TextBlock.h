//
// Created by signal on 12/2/23.
//

#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H
#include <string>
#include <utility>
#include <raylib.h>
#include "interfaces/Drawable.h"
#include "interfaces/Text.h"


class TextBlock final : public Drawable, public Text {
private:
    float x{};
    float y{};
    float widthPercentage{};
    float heightPercentage{};
    std::string text{};
    Font font;
    Color tint;
    float fontSize;
    float spacing;
    bool wordWrap{};
public:
    TextBlock(const float widthPercentage, const float heightPercentage, std::string text, const Font& font, const Color tint,
              const float fontSize, const float spacing, const bool wordWrap)
              :
              widthPercentage{widthPercentage}, heightPercentage{heightPercentage}, text{std::move(text)},
              font{font}, tint{tint}, fontSize{fontSize}, spacing{spacing}, wordWrap{wordWrap}
    {}
    void Draw() override;
    void SetText(const std::string& text) override;
    std::string GetText() override;
    void SetWordWrap(bool wordWrap) override;
    void DrawTextBox(const Font& font, const char *text, Rectangle rec, float fontSize, float spacing,
        bool wordWrap, Color tint);
};



#endif //TEXTBLOCK_H
