//
// Created by Joshua on 11/17/2017.
//
#include "NormalBrush.h"

NormalBrush::NormalBrush() {
    size = 2;
    brushName = "Brush";
}

//Setters
void NormalBrush::setColor(color colorIn) {
    currentColor = colorIn;
}

void NormalBrush::setSize(int sizeIn) {
    size = sizeIn;
}

//Getters
color NormalBrush::getColor() const {
    return currentColor;
}

int NormalBrush::getSize() const {
    return size;
}

//Methods
void NormalBrush::changeColor(int colorChoice) {
    if (colorChoice > 9 || colorChoice < 0) {
        cout << "Invalid color input" << endl;
    }
    else {
        switch(colorChoice) {
            case (1):
                //Make it red
                currentColor = {1, 0, 0};
                cout << "Color switched to red." << endl;
                break;
            case (2):
                //Orange
                currentColor = {1, .64, 0};
                cout << "Color switched to orange." << endl;
                break;
            case (3):
                //Yellow
                currentColor = {1, 1, 0};
                cout << "Color switched to yellow." << endl;
                break;
            case (4):
                //Green
                currentColor = {0, .5, 0};
                cout << "Color switched to green." << endl;
                break;
            case (5):
                //Blue
                currentColor = {0, 0, 1};
                cout << "Color switched to blue." << endl;
                break;
            case (6):
                //Purple
                currentColor = {.29, 0, .5};
                cout << "Color switched to purple." << endl;
                break;
            case (7):
                //Pink
                currentColor = {1, .75, .80};
                cout << "Color switched to pink." << endl;
                break;
            case (8):
                //White
                currentColor = {1, 1, 1};
                cout << "Color switched to white." << endl;
                break;
            case (9):
                //Gray
                currentColor = {.75, .75, .75};
                cout << "Color switched to gray." << endl;
                break;
            case (0):
                //Black
                currentColor = {0, 0, 0};
                cout << "Color switched to black." << endl;
                break;
        }
    }
}