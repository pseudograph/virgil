#include <iostream>

#include "entities/background/Background.h"
#include "entities/button/Button.h"
#include "entities/sprite/Sprite.h"
#include "entities/text/TextBlock.h"
#include "virgil/Virgil.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Virgil virgil;
    Screen screen{"image"};
    // Background test
    const std::shared_ptr<Entity> background = std::make_shared<Background>("19201080bg.png", WHITE);
    screen.setLayerCount(MAX_LAYERS);
    screen.insertEntity(LAYER::BACKGROUND, background);
    // Text test
    const std::shared_ptr<Entity> textBlock = std::make_shared<TextBlock>(0, 0, 1920, 1080, "The quick brown fox jumped over the lazy dog.", GetFontDefault(), RED, 120, 1, true);
    screen.insertEntity(LAYER::TEXT, textBlock);
    // Sprite test
    const std::shared_ptr<Entity> sprite = std::make_shared<Sprite>("19201080sprite1.png", WHITE, LEFT, 0, BASE_WIDTH, BASE_HEIGHT, 0);
    screen.insertEntity(LAYER::SPRITES, sprite);
    // Button test
    const std::shared_ptr<Entity> button = std::make_shared<Button>(std::vector<std::string>{"300400buttonup.png", "300400hover.png", "300400down.png"}, 700, 100, 300, 400, 0.0, WHITE);
    screen.insertEntity(LAYER::GUI, button);
    virgil.viewport.insertScreen(screen);
    virgil.run();
    return 0;
}
