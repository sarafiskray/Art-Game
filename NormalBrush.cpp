//
// Created by Joshua on 11/17/2017.
//
#include "NormalBrush.h"

NormalBrush::NormalBrush(Map *mapIn) {
    size = 1;
    painting = false;
    currentColorIndex = 0;
    brushName = "Brush";
    thisMap = mapIn;

    cout << "Norm constructed" << endl;
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
