//
// Created by signal on 12/3/23.
//

#include "ScaleWHVisitor.h"

#include <fmt/core.h>

void ScaleWHVisitor::visit(TextBlock& textblock) {
    textblock.scaleWH(scaleWidthBy, scaleHeightBy);
}

void ScaleWHVisitor::visit(Background& background) {
    fmt::println(stderr, "WARNING: [ScaleWHVisitor::visit]: visiting Background, which is not implemented.");
}
