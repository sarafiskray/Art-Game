//
// Created by Saraf Ray on 11/16/17.
//

#ifndef THE_STATISTICS_DOTTEDBRUSH_H
#define THE_STATISTICS_DOTTEDBRUSH_H

#include "Brush.h"

class DottedBrush : public Brush {

private:
    int dottedSpeed;

public:
    int getDottedSpeed() const;
    void setDottedSpeed(int speedIn);
    void changeColor();
    DottedBrush();
    DottedBrush(int ds);

};





#endif //THE_STATISTICS_DOTTEDBRUSH_H
