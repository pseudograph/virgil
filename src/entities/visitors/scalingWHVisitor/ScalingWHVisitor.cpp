//
// Created by signal on 12/2/23.
//

#include "ScalingWHVisitor.h"

void ScalingWHVisitor::visit(TextBlock& textBlock) {
    textBlock.scaleWidth(scaleWidthBy);
    textBlock.scaleHeight(scaleHeightBy);
}
