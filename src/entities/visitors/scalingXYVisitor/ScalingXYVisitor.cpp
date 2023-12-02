//
// Created by signal on 12/2/23.
//

#include "ScalingXYVisitor.h"

void ScalingXYVisitor::visit(TextBlock& textBlock) {
    textBlock.scaleX(scaleXBy);
    textBlock.scaleY(scaleYBy);
}
