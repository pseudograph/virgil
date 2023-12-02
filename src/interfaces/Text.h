//
// Created by signal on 12/2/23.
//

#ifndef TEXT_H
#define TEXT_H
#include <string>

class Text {
public:
    virtual void SetText(const std::string& text) = 0;
    virtual std::string GetText() = 0;
    virtual void SetWordWrap(bool wordWrap) = 0;
    virtual ~Text() = default;
};
#endif //TEXT_H
