//
// Created by Andrew Ridgely on 11/7/17.
// Will be much further implemented with Graphics
//


#ifndef THE_STATISTICS_SPLATTER_H
#define THE_STATISTICS_SPLATTER_H


#include "Headings.h"
#include "graphics.h"


class Splatter {

private:
    color fill;
    int width = 10;
    int height = 10;
    point location;


public:
    Splatter();
    Splatter(int r, int g, int b, int xLoc, int yLoc);

    void setFill(color fillIn);
    void setX(int xIn);
    void setY(int yIn);

    color getFill() const;
    int getX() const;
    int getY() const;

    void draw() const;
};

#endif //THE_STATISTICS_SPLATTER_H
