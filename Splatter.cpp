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

void Splatter::drawSplatter() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(location.x, location.y);
    // bottom left corner
    glVertex2i(location.x, location.y + height);
    // bottom right corner
    glVertex2i(location.x + width, location.y + height);
    // top right corner
    glVertex2i(location.x + width, location.y);
    glEnd();
}

Splatter::Splatter() {
}

Splatter::Splatter(int r, int g, int b, int xLoc, int yLoc) {
        fill.red = r;
        fill.green = g;
        fill.blue = b;
        location.x = xLoc;
        location.y = yLoc;
}