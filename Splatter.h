//
// Created by Andrew Ridgely on 11/7/17.
// Will be much further implemented with Graphics
//

struct skin {
    double red;
    double green;
    double blue;
};

#ifndef THE_STATISTICS_SPLATTER_H
#define THE_STATISTICS_SPLATTER_H

class Splatter {

private:
    skin fill;

public:
    Splatter(int r, int g, int b) {
        fill.red = r;
        fill.green = g;
        fill.blue = b;
    }
};

#endif //THE_STATISTICS_SPLATTER_H
