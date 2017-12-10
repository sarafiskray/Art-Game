//
// Created by Joshua on 11/19/2017.
//

#include "Brush.h"
#include "DottedBrush.h"
#include <unistd.h>

DottedBrush::DottedBrush(Map *mapIn) {
    cout << "Made a new brush?" << endl;
    dottedSpeed = 1;
    size = 10;
    painting = false;
    currentColorIndex = 0;
    brushName = "Dotted Brush";
    thisMap = mapIn;
};


void DottedBrush::drawHere(point location)   {
    if(painting) {
        //usleep(1000 * dottedSpeed);
        thisSplatter = Splatter(getColor(), location, size);
        //Add the splatter to the background vector too
        thisMap->addSplatter(thisSplatter);
    }
}