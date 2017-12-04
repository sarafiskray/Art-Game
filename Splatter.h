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

public:
    Splatter(int r, int g, int b) {
        fill.red = r;
        fill.green = g;
        fill.blue = b;
    }

    void setFill(struct skin fillIn);

    struct skin getFill() const;
};

#endif //THE_STATISTICS_SPLATTER_H
