#include "pch.h"
#include "ovni.hpp"

void COvni::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void COvni::getPosition(int* x, int* y) {
    *x = this->x;
    *y = this->y;
}

void COvni::setName(string name) {
    this->name = name;
}

string COvni::getName() {
    return this->name;
}

void COvni::setColor(int color) {
    this->color = color;
}

int COvni::getColor() {
    return this->color;
}