//
// Created by signal on 12/3/23.
//

#include "ScaleXYVisitor.h"

#include <fmt/core.h>

void ScaleXYVisitor::visit(TextBlock& textblock) {
    textblock.scaleXY(scaleXBy, scaleYBy);
}

void ScaleXYVisitor::visit(Background& background) {
    fmt::println(stderr, "WARNING: [ScaleXYVisitor::visit]: visiting Background, which is not implemented.");
}

void ScaleXYVisitor::visit(Sprite& sprite) {
    sprite.scaleXY(scaleXBy, scaleYBy);
}
