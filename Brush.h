//
// Created by Joshua on 11/7/2017.
//

#ifndef THE_STATISTICS_BRUSH_H
#define THE_STATISTICS_BRUSH_H


#include <iostream>
#include <vector>
#include <string>

#include "Splatter.h"
#include "Map.h"

using namespace std;

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
    //current color
    color currentColor = colorPalette[0];
    int currentColorIndex;
    Map thisMap;


public:
    bool getPainting() const;

    color getColor() const;
    color getPrevColor() const;
    color getNextColor() const;

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
     * Modifies: currentColorIndex
     * Effects: Changes the selected color to the next one in the colorPalette
     * virtual because some future brushes might not have just one color
     */
    virtual void changeColor(int choice);

    /*
     * draw
     * Requires: point location, location for splatter to go
     * Modifies: thisSplatter
     * Effects: changes thisSplatter to something dependent on current location
     */
    void draw(point location);

    void changeSize(int choice);

};

#endif //THE_STATISTICS_BRUSH_H
