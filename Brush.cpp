//
// Created by Joshua on 11/17/2017.
//

using namespace std;

#include "Brush.h"
#include <string>
#include <iostream>


bool Brush::getPainting() const {
    return painting;
}

void Brush::togglePaint() {
    if (painting) {
        painting = false;
    }
    else {
        painting = true;
    }

    if (painting) {
        cout << "Painting is on" << endl;
    }

    else {
        cout << "Painting is off." << endl;
    }
}

string Brush::getBrushName() const {
    return brushName;
}

void Brush::changeColor(int choice) {
    cout << "Change color is running" << endl;
    //Next color
    if (choice == 0) {
        if (currentColorIndex == (colorPalette.size() - 1)) {
            currentColorIndex = 0;
        }
        else {
            currentColorIndex += 1;
        }

        cout << "current color index = " << currentColorIndex << endl;
    }
    //Prev color
    else {
        if (currentColorIndex == 0) {
            currentColorIndex = colorPalette.size() - 1;
        }
        else {
            currentColorIndex -= 1;
        }

        cout << "current color index = " << currentColorIndex << endl;
    }

    currentColor = colorPalette[currentColorIndex];
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
    return currentColor;
}

int Brush::getSize() const {
    return size;
}

void Brush::changeSize(int choice) {
    if (choice == 0) {
        size += 5;
    }
    else {
        if (size > 5) {
            size -= 5;
        }
    }
}

void Brush::drawHere(const point location) {
    if(painting) {
        thisSplatter = Splatter(getColor(), location, getSize());

        thisMap->addSplatter(thisSplatter);
        cout << "Splatter placed at " << location.x << "," << location.y << endl;
        cout << "Size is: " << size << endl;
    }


}