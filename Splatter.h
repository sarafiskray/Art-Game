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
    //Splatter's paint color
    color fill;
    //Dimensions
    int width = 10;
    int height = 10;
    //Location
    point location;


public:
    //Constructors
    Splatter();
    Splatter(color colorIn, point locationIn, int sizeIn);
    Splatter(int r, int g, int b, int xLoc, int yLoc, int sizeIn);

    //Setters
    void setFill(color fillIn);
    void setX(int xIn);
    void setY(int yIn);

    //Getters
    int getSize() const;
    color getFill() const;
    int getX() const;
    int getY() const;
};

#endif //THE_STATISTICS_SPLATTER_H
