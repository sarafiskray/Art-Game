//
// Created by Joshua on 11/17/2017.
//

using namespace std;

#include "Brush.h"
#include <string>
#include <iostream>




void Brush::togglePaint() {
    painting = !painting;
    string descriptor;
    painting ? descriptor = "on" : descriptor = "off";
    cout << "Painting is now " << descriptor << endl;
}

string Brush::getBrushName() {
    return brushName;
}

void Brush::changeColor() {
    currentColorIndex++;
}

color Brush::getPrevColor() const {
    if (currentColorIndex == 0) {
        return colorPalette[colorPalette.size() -1];
    }
    else {
        return colorPalette[currentColorIndex - 1];
    }
}

color Brush::getNextColor() const {
    if (currentColorIndex == colorPalette.size()) {
        return colorPalette[0];
    }
    else {
        return colorPalette[currentColorIndex+1];
    }
}

color Brush::getColor() const {
    return colorPalette[currentColorIndex];
}

void Brush::draw(point location) {
    //If painting is toggled on, start placing splatters of the current color and current location. Location will modify frequently
    if(painting) {
        thisSplatter = Splatter(colorPalette[currentColorIndex].red, colorPalette[currentColorIndex].blue, colorPalette[currentColorIndex].green, location.x, location.y);
        thisSplatter.drawSplatter();
    }
}