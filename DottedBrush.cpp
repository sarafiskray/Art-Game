//
// Created by Joshua on 11/19/2017.
//

#include "Brush.h"
#include "DottedBrush.h"

DottedBrush::DottedBrush() {
    brushName = "Dotted Brush";
};

int DottedBrush::getDottedSpeed() const {
    return dottedSpeed;
}

void DottedBrush::setDottedSpeed(int speedIn) {
    dottedSpeed = speedIn;
}

void DottedBrush::changeColor() {

}
