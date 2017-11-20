//
// Created by Joshua on 11/7/2017.
//

#include <Color>;

#ifndef THE_STATISTICS_BRUSH_H
#define THE_STATISTICS_BRUSH_H

class Brush {

private:
    //Size multiplier for the brush splatters. To be implemented with graphics
    int size;
    //Whether or not the brush is currently painting
    bool painting;
    //The splatter being painted currently
    Splatter thisSplatter;

public:
    /*
     * togglePaint
     * Required: Nothing
     * Modifies: bool painting
     * Effects: toggles the draw functions for splatters on and off
     */
    void togglePaint() {
    }

    /*
     * changeColor
     * Requires: Nothing
     * Modifies: thisSplatter
     * Effects: Changes this splatter to a splatter of the selected color
     * Pure virtual because some brushes don't have just one color
     */
    pure virtual void changeColor = 0;

};

#endif //THE_STATISTICS_BRUSH_H
