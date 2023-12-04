//
// Created by signal on 12/3/23.
//

#include "ScaleWHVisitor.h"

void ScaleWHVisitor::visit(TextBlock& textblock) {
    textblock.scaleWH(scaleWidthBy, scaleHeightBy);
}

void ScaleWHVisitor::visit(Background& background) {
    background.scaleWH(scaleWidthBy, scaleHeightBy);
}
