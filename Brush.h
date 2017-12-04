//
// Created by Joshua on 11/7/2017.
//

#ifndef THE_STATISTICS_BRUSH_H
#define THE_STATISTICS_BRUSH_H


#include <iostream>
#include <vector>
#include <string>

#include "Splatter.h"

using namespace std;

struct color {
    double red;
    double green;
    double blue;
};

color black = {0, 0, 0};
color red = {1, 0, 0};
color green = {0, 1, 0};
color blue = {0, 0, 1};

class Brush {


private:
    //Size multiplier for the brush splatters. To be implemented with graphics
    int size;
    //Whether or not the brush is currently painting
    bool painting;
    //The splatter being painted currently
    Splatter thisSplatter;
    //Name for brush
    string brushName;
    //current color
    color currentColor = colorPalette[0];
    //all accessible colors
    vector<color> colorPalette = {black, red, green, blue};

public:
    string getBrushName();
    //No setBrush, brush is set by changeBrush

    /*
     * togglePaint
     * Required: Nothing
     * Modifies: bool painting
     * Effects: toggles the draw functions for splatters on and off
     */
    void togglePaint();

    /*
     * changeColor
     * Requires: Nothing
     * Modifies: thisSplatter
     * Effects: Changes this splatter to a splatter of the selected color
     * Pure virtual because some brushes don't have just one color
     */
    virtual void changeColor() = 0;

};

#endif //THE_STATISTICS_BRUSH_H
