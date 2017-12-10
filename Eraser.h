//
// Created by Saraf Ray on 12/9/17.
//

#ifndef THE_STATISTICS_ERASER_H
#define THE_STATISTICS_ERASER_H


#include "Brush.h"

class Eraser : public Brush {
public:
    Eraser(Map *mapIn);
    void changeColor(int choice) override;
    void drawHere(const point location) override;

};


#endif //THE_STATISTICS_ERASER_H
