//
// Created by Saraf Ray on 11/16/17.
//

#ifndef THE_STATISTICS_DOTTEDBRUSH_H
#define THE_STATISTICS_DOTTEDBRUSH_H

#include "Brush.h"

//Dotted Brush
class DottedBrush : public Brush {

private:
    //higher speed, the fewer dots
    //lower speed means more dots
    int dottedSpeed;

public:

    //Constructor
    DottedBrush(Map *mapIn);

    //Only overriden method
    void drawHere(point location) override;
};

#endif //THE_STATISTICS_DOTTEDBRUSH_H
