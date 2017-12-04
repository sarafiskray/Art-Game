//
// Created by Andrew Ridgely on 11/7/17.
// Will be much further implemented with Graphics
//


#ifndef THE_STATISTICS_SPLATTER_H
#define THE_STATISTICS_SPLATTER_H


#include "Headings.h"


class Splatter {

private:
    skin fill;
    int width = 10;
    int height = 10;
    point location;


public:
    Splatter();
    Splatter(int r, int g, int b, int xLoc, int yLoc);
    void setFill(skin fillIn);

    skin getFill() const;

    void draw() const;
};

#endif //THE_STATISTICS_SPLATTER_H
