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

}
