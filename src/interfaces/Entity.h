//
// Created by signal on 12/3/23.
//
#pragma once


class Visitor;

class Entity {
public:
    virtual void accept(Visitor& visitor) = 0;
};
