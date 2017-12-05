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

color black = {0, 0, 0};
color red = {1, 0, 0};
color green = {0, 1, 0};
color blue = {0, 0, 1};
color pink = {1, .753, .796};
color indigo = {.294, 0, .509};
color gold = {1, .843, 0};
color cyan = {0, 1, 1};
color yellow = {1, 1, 0};
color orange = {1, .647, 0};
color maroon = {.502, 0, 0};
color brown = {.627, .321, .176};
color gray = {.66, .66, .66};




class Brush {


protected:
    //Size multiplier for the brush splatters. To be implemented with graphics
    int size;
    //Whether or not the brush is currently painting
    bool painting;
    //The splatter being painted currently
    Splatter thisSplatter;
    //Name for brush
    string brushName;
    //all accessible colors
    vector<color> colorPalette = {indigo, blue, cyan, green, yellow, gold, orange, pink, red, maroon, brown, gray, black};
    //current color
    color currentColor = colorPalette[0];
    int currentColorIndex;


public:
    string getBrushName();
    //No setBrush, brush is set by changeBrush

    /*
     * togglePaint
     * Required: Nothing
     * Modifies: bool painting
     * Effects: toggles the draw functions for splatters on and off
     * In normal brush, is consistent. Dotted brush is intermittent
     */
    virtual void togglePaint();

    /*
     * changeColor
     * Requires: Nothing
     * Modifies: thisSplatter, currentColorIndex
     * Effects: Changes this splatter to a splatter of the selected color
     * virtual because some future brushes might not have just one color
     */
    virtual void changeColor();

};

#endif //THE_STATISTICS_BRUSH_H
