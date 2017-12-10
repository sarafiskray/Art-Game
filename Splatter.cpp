//
// Created by Joshua on 11/17/2017.
//

#include "Splatter.h"

color Splatter::getFill() const {
    return fill;
}

void Splatter::setFill(color fillIn) {
    fill = fillIn;
}

int Splatter::getX() const {
    return location.x;
}
int Splatter::getY() const {
    return location.y;
}

void Splatter::setX(int xIn) {
    location.x = xIn;
}

void Splatter::setY(int yIn) {
    location.y = yIn;
}

int Splatter::getSize() const {
    return height;
}


Splatter::Splatter() {}

Splatter::Splatter(color colorIn, point locationIn, int sizeIn) {
    fill = colorIn;
    location = locationIn;
    height = sizeIn;
    width = sizeIn;
}

Splatter::Splatter(int r, int g, int b, int xLoc, int yLoc, int sizeIn) {
    fill.red = r;
    fill.green = g;
    fill.blue = b;
    location.x = xLoc;
    location.y = yLoc;
    height = sizeIn;
    width = sizeIn;
}