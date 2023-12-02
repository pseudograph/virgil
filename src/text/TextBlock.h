//
// Created by signal on 12/2/23.
//

#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H
#include <string>
#include <utility>


class TextBlock {
private:
    int widthPercentage{};
    int heightPercentage{};
    std::string text;
public:
    TextBlock(const int widthPercentage, const int heightPercentage, std::string  text)
    : widthPercentage{widthPercentage}, heightPercentage{heightPercentage}, text{std::move(text)}
    {}
    

};



#endif //TEXTBLOCK_H
