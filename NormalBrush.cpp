//
// Created by Joshua on 11/17/2017.
//
#include "NormalBrush.h"

NormalBrush::NormalBrush(Map mapIn) {
    size = 2;
    brushName = "Brush";
    thisMap = mapIn;
    currentColorIndex = 0;
}

//Setters
void NormalBrush::setColor(color colorIn) {
    currentColor = colorIn;
}

void NormalBrush::setSize(int sizeIn) {
    size = sizeIn;
}

//Getters
color NormalBrush::getColor() const {
    return currentColor;
}

int NormalBrush::getSize() const {
    return size;
}
