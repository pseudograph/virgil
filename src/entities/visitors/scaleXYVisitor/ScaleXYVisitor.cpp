//
// Created by signal on 12/3/23.
//

#include "ScaleXYVisitor.h"

void ScaleXYVisitor::visit(TextBlock& textblock) {
    textblock.scaleXY(scaleXBy, scaleYBy);
}

void ScaleXYVisitor::visit(Background& background) {
    background.scaleXY(scaleXBy, scaleYBy);
}
