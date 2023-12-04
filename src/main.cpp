#include <iostream>

#include "entities/background/Background.h"
#include "virgil/Virgil.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Virgil virgil;
    Screen screen{"image"};
    const std::shared_ptr<Entity> background = std::make_shared<Background>("bg.png", 0.0, 0.0, 1.0, 1.0, WHITE);
    screen.setLayerCount(1);
    screen.insertEntity(0, background);
    virgil.viewport.insertScreen(screen);
    virgil.run();
    return 0;
}
