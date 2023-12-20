//
// Created by signal on 12/3/23.
//

#include "DrawVisitor.h"

void DrawVisitor::visit(TextBlock& textblock) {
    textblock.draw();
}

void DrawVisitor::visit(Background& background) {
    background.draw();
}

void DrawVisitor::visit(Sprite& sprite) {
    sprite.draw();
}

void DrawVisitor::visit(Button& button) {
    button.draw();
}
