//
// Created by signal on 12/2/23.
//

#include "ScalingVisitor.h"

void ScalingVisitor::visit(TextBlock& textBlock) {
    textBlock.scaleWidth(scaleXBy);
    textBlock.scaleHeight(scaleYBy);
}
