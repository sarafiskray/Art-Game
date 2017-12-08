//
// Created by Joshua on 12/3/2017.
//

#ifndef THE_STATISTICS_HEADINGS_H
#define THE_STATISTICS_HEADINGS_H

using namespace std;
#include <vector>

struct point {
    int x;
    int y;
};

struct color {
    double red;
    double green;
    double blue;
};

extern color indigoX, blueX, cyanX, greenX, yellowX, goldX, orangeX, pinkX, redX, maroonX, brownX, grayX, blackX;

extern vector<color> colorPalette;
#endif


