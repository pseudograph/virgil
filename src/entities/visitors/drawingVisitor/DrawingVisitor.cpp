//
// Created by signal on 12/2/23.
//

#include "DrawingVisitor.h"

void DrawingVisitor::visit(TextBlock& button) {
    button.draw();
}
