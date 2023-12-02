//
// Created by signal on 12/2/23.
//

#include "TextBlock.h"
#include "config/Consts.h"

void TextBlock::draw() const {
    DrawTextBox(font, text.c_str(), {x, y, width * SCREEN_WIDTH, height * SCREEN_HEIGHT}, fontSize,
                spacing, wordWrap, tint);
}

void TextBlock::setText(const std::string& text) {
    this->text = text;
}

std::string TextBlock::getText() const {
    return text;
}

void TextBlock::setWordWrap(const bool wordWrap) {
    this->wordWrap = wordWrap;
}

// Taken from https://www.raylib.com/examples/text/loader.html?name=text_rectangle_bounds
/**
 * \brief
 * \param font  Font
 * \param text Text
 * \param rec Rectangle that specifies text bounds for wrapping
 * \param fontSize Font size
 * \param spacing Spacing between glyphs
 * \param wordWrap Enable/disable word wrap. Still wraps when false, but words will be split
 * \param tint Color to tint text
 */
void TextBlock::DrawTextBox(const Font& font, const char* text, const Rectangle rec, const float fontSize,
                                        const float spacing, const bool wordWrap, const Color tint) const {
    const unsigned int length{TextLength(text)};  // Total length in bytes of the text, scanned by codepoints in loop
    float textOffsetY = 0;          // Offset between lines (on line break '\n')
    float textOffsetX = 0.0f;       // Offset X to next character to draw
    const float scaleFactor = fontSize / static_cast<float>(font.baseSize);     // Character rectangle scaling factor
    // Word/character wrapping mechanism variables
    enum {
        MEASURE_STATE = 0,
        DRAW_STATE = 1
    };
    int state{wordWrap ? MEASURE_STATE : DRAW_STATE};
    int startLine{-1};         // Index where to begin drawing (where a line begins)
    int endLine{-1};           // Index where to stop drawing (where a line ends)
    int lastk{-1};             // Holds last value of the character position
    for (int i{0}, k{0}; i < length; i++, k++) {
        // Get next codepoint from byte string and glyph index in font
        int codepointByteCount{0};
        const int codepoint{GetCodepoint(&text[i], &codepointByteCount)};
        const int index{GetGlyphIndex(font, codepoint)};
        // NOTE: Normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
        // but we need to draw all of the bad bytes using the '?' symbol moving one byte
        if (codepoint == 0x3f) {
            codepointByteCount = 1;
        }
        i += (codepointByteCount - 1);
        float glyphWidth{0};
        if (codepoint != '\n')
        {
            if ((font.glyphs[index].advanceX == 0)) {
                glyphWidth = font.recs[index].width * scaleFactor;
            } else {
                glyphWidth = static_cast<float>(font.glyphs[index].advanceX) * scaleFactor;
            }
            if (i + 1 < length) {
                glyphWidth = glyphWidth + spacing;
            }
        }
        // NOTE: When wordWrap is ON we first measure how much of the text we can draw before going outside of the rec container
        // We store this info in startLine and endLine, then we change states, draw the text between those two variables
        // and change states again and again recursively until the end of the text (or until we get outside of the container).
        // When wordWrap is OFF we don't need the measure state so we go to the drawing state immediately
        // and begin drawing on the next line before we can get outside the container.
        if (state == MEASURE_STATE)
        {
            // TODO: There are multiple types of spaces in UNICODE, maybe it's a good idea to add support for more
            // Ref: http://jkorpela.fi/chars/spaces.html
            if ((codepoint == ' ') || (codepoint == '\t') || (codepoint == '\n')) {
                endLine = i;
            }
            if ((textOffsetX + glyphWidth) > rec.width) {
                endLine = (endLine < 1) ? i : endLine;
                if (i == endLine) {
                    endLine -= codepointByteCount;
                }
                if ((startLine + codepointByteCount) == endLine) {
                    endLine = (i - codepointByteCount);
                }
                state = !state; // invert enum
            } else if ((i + 1) == length) {
                endLine = i;
                state = !state;
            } else if (codepoint == '\n') {
                state = !state;
            }
            if (state == DRAW_STATE) {
                textOffsetX = 0;
                i = startLine;
                glyphWidth = 0;
                // Save character position when we switch states
                const int tmp{lastk};
                lastk = k - 1;
                k = tmp;
            }
        }
        else {
            if (codepoint == '\n') {
                if (!wordWrap) {
                    textOffsetY += static_cast<float>((font.baseSize + font.baseSize / 2)) * scaleFactor;
                    textOffsetX = 0;
                }
            } else {
                if (!wordWrap && ((textOffsetX + glyphWidth) > rec.width)) {
                    textOffsetY += static_cast<float>((font.baseSize + font.baseSize / 2)) * scaleFactor;
                    textOffsetX = 0;
                }
                // When text overflows rectangle height limit, just stop drawing
                if ((textOffsetY + static_cast<float>(font.baseSize) * scaleFactor) > rec.height) {
                    break;
                }
                // Draw current character glyph
                if ((codepoint != ' ') && (codepoint != '\t')) {
                    DrawTextCodepoint(font, codepoint, (Vector2){ rec.x + textOffsetX, rec.y + textOffsetY }, fontSize, tint);
                }
            }
            if (wordWrap && (i == endLine)) {
                textOffsetY += static_cast<float>((font.baseSize + font.baseSize / 2)) * scaleFactor;
                textOffsetX = 0;
                startLine = endLine;
                endLine = -1;
                glyphWidth = 0;
                k = lastk;
                state = !state;
            }
        }
        if ((textOffsetX != 0) || (codepoint != ' ')) {
            textOffsetX += glyphWidth;  // avoid leading spaces
        }
    }
}

void TextBlock::setX(const float x) {
    this->x = x;
}

void TextBlock::setY(const float y) {
    this->y = y;
}

void TextBlock::setXY(const float x, const float y) {
    setX(x);
    setY(y);
}

void TextBlock::scaleX(const float multiplier) {
    x *= multiplier;
}

void TextBlock::scaleY(const float multiplier) {
    y *= multiplier;
}

void TextBlock::scaleXY(const float multiplier) {
    scaleX(multiplier);
    scaleY(multiplier);
}

void TextBlock::setWidth(const float width) {
    this->width = width;
}

void TextBlock::setHeight(const float height) {
    this->height = height;
}

void TextBlock::scaleWidth(const float multiplier) {
    width *= multiplier;
}

void TextBlock::scaleHeight(const float multiplier) {
    height *= multiplier;
}

void TextBlock::scaleBoth(const float multiplier) {
    scaleWidth(multiplier);
    scaleHeight(multiplier);
}
