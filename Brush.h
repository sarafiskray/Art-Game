//
// Created by Joshua on 11/7/2017.
//

#include <Color>;

#ifndef THE_STATISTICS_BRUSH_H
#define THE_STATISTICS_BRUSH_H

class Brush {

private:
    //Size multiplier for the brush splatters
    int size;
    bool painting;
    Splatter thisSplatter;

public:
    /*
     * togglePaint
     * Required: Nothing
     * Modifies: bool painting
     * Effects: toggles the draw functions for splatters on and off
     */
    void togglePaint() {
        painting = !painting;
        string descriptor;
        painting ? descriptor = "on" : descriptor = "off";
        
    }

};

#endif //THE_STATISTICS_BRUSH_H
