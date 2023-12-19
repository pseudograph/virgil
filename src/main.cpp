#include <iostream>

#include "entities/background/Background.h"
#include "entities/text/TextBlock.h"
#include "virgil/Virgil.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Virgil virgil;
    Screen screen{"image"};
    const std::shared_ptr<Entity> background = std::make_shared<Background>("19201080bg.png", WHITE);
    screen.setLayerCount(1);
    screen.insertEntity(0, background);
    const std::shared_ptr<Entity> textBlock = std::make_shared<TextBlock>(0, 0, 1920, 1080, "The quick brown fox jumped over the lazy dog.", GetFontDefault(), RED, 120, 1, true);
    screen.insertEntity(0, textBlock);
    virgil.viewport.insertScreen(screen);
    virgil.run();
    return 0;
}
