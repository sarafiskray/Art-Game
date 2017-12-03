//
// Created by Joshua on 11/17/2017.
//

#include "Brush.h"

void Brush::togglePaint() {
    painting = !painting;
    string descriptor;
    painting ? descriptor = "on" : descriptor = "off";
    cout << "Painting is now " << descriptor << endl;
}

string Brush::getBrush() {
    return brushName;
}