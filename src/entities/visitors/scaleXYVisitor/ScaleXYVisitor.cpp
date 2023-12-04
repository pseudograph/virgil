//
// Created by signal on 12/3/23.
//

#include "ScaleXYVisitor.h"

void ScaleXYVisitor::visit(TextBlock& textblock) {
    textblock.scaleX(scaleXBy);
    textblock.scaleY(scaleYBy);
}

void ScaleXYVisitor::visit(Background& background) {
    background.scaleX(scaleXBy);
    background.scaleY(scaleYBy);
}
