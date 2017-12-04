//
// Created by Andrew Ridgely on 11/7/17.
// Will be much further implemented with Graphics
//


#ifndef THE_STATISTICS_SPLATTER_H
#define THE_STATISTICS_SPLATTER_H


#include "Character.h"


class Splatter {

private:
    skin fill;
    int width = 10;
    int height = 10;
    point location;


public:
    Splatter(int r, int g, int b, int xLoc, int yLoc) {
        fill.red = r;
        fill.green = g;
        fill.blue = b;
        location.x = xLoc;
        location.y = yLoc;
    }

    void setFill(skin fillIn);

    skin getFill() const;

    void setX(int xIn);
    void setY(int yIn);

    int getX() const;
    int getY() const;

    void draw() const;
};

#endif //THE_STATISTICS_SPLATTER_H
