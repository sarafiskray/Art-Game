//
// Created by Joshua on 12/3/2017.
//

#ifndef THE_STATISTICS_HEADINGS_H
#define THE_STATISTICS_HEADINGS_H

using namespace std;
#include <vector>

//Struct point, in from {x, y} obviously
struct point {
    int x;
    int y;
};

//Color struct, {r, g, b}
struct color {
    double red;
    double green;
    double blue;
};

//Make some colors accessible to everyone
extern color indigoX, blueX, cyanX, greenX, yellowX, goldX, orangeX, pinkX, redX, maroonX, brownX, grayX, blackX, whiteX;

//Color palette accessible to everyone, filled with the colors
extern vector<color> colorPalette;
#endif


