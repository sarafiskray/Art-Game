//
// Created by Saraf Ray on 12/9/17.
//

#include "Brush.h"
#include "Eraser.h"

Eraser::Eraser(Map *mapIn) {
    size = 10;
    thisMap = mapIn;
    painting = false;
    currentColor = whiteX;
    brushName = "Eraser";
}

void Eraser::changeColor(int choice) {
    cout << "Eraser cannot change colors." << endl;
}

void Eraser::drawHere(const point location) {
    if(painting) {
        //usleep(1000 * dottedSpeed);
        thisSplatter = Splatter(getColor(), location, size);
        //Add the splatter to the background vector too
        thisMap->addSplatter(thisSplatter);
    }
}

color Eraser::getColor() const {
    return whiteX;
}

color Eraser::getNextColor() const {
    return whiteX;
}

color Eraser::getPrevColor() const {
    return whiteX;
}