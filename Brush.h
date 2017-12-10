//
// Created by Joshua on 11/7/2017.
//

#ifndef THE_STATISTICS_BRUSH_H
#define THE_STATISTICS_BRUSH_H


#include <iostream>
#include <vector>
#include <string>
#include "graphics.h"

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
    color currentColor;
    //how to figure out which is the current color, b/c currentColor wasn't working well
    int currentColorIndex;
    //pointer to the Map being edited
    Map *thisMap;


public:

    //Getters

    int getSize() const;
    bool getPainting() const;

    color getColor() const;
    color getPrevColor() const;
    color getNextColor() const;

    string getBrushName() const;
    //No setBrushName, they're pre-set

    //No setters, because they're almost all toggles anyway

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
     * drawHere
     * Requires: point location, location for splatter to go
     * Modifies: thisSplatter
     * Effects: changes thisSplatter to something dependent on current location
     */
    virtual void drawHere(const point location) = 0;

    /*
     * changeSize
     * Requires: int choice, for changing size up vs down
     * Modifes: Brush::size
     * Effects: changes size up or down by 5
     */
    void changeSize(int choice);

};

#endif //THE_STATISTICS_BRUSH_H
