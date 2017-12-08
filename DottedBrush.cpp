//
// Created by Joshua on 11/19/2017.
//

#include "Brush.h"
#include "DottedBrush.h"

DottedBrush::DottedBrush(Map mapIn) {
    brushName = "Dotted Brush";
    thisMap = mapIn;
    currentColorIndex = 0;
};

void DottedBrush::setMap(Map mapIn) {
    thisMap = mapIn;
}

int DottedBrush::getDottedSpeed() const {
    return dottedSpeed;
}

void DottedBrush::setDottedSpeed(int speedIn) {
    dottedSpeed = speedIn;
}

void DottedBrush::changeColor() {

}
