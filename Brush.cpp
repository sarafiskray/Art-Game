//
// Created by Joshua on 11/17/2017.
//

using namespace std;

#include "Brush.h"
#include <string>
#include <iostream>




virtual void Brush::togglePaint() {
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

void Brush::draw(point location) {
    //If painting is toggled on, start placing splatters of the current color and current location. Location will modify frequently
    if(painting) {
        thisSplatter = Splatter(colorPalette[currentColorIndex].red, colorPalette[currentColorIndex].blue, colorPalette[currentColorIndex].green, location.x, location.y);
        thisSplatter.drawSplatter();
    }
}