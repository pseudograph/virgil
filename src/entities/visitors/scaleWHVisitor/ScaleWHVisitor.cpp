//
// Created by signal on 12/3/23.
//

#include "ScaleWHVisitor.h"

void ScaleWHVisitor::visit(TextBlock& textblock) {
    textblock.scaleWidth(scaleWidthBy);
    textblock.scaleHeight(scaleHeightBy);
}

void ScaleWHVisitor::visit(Background& background) {
    background.scaleWidth(scaleWidthBy);
    background.scaleHeight(scaleHeightBy);
}
