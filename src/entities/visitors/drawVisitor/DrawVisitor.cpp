//
// Created by signal on 12/3/23.
//

#include "DrawVisitor.h"

void DrawVisitor::visit(TextBlock& textblock) {
    textblock.draw();
}
