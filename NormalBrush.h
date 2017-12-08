//
// Created by Joshenberg
//

/*
 * Goals for this file:
 * A brush that is implemented normally. Has a single color, size
 * Its xPos and yPos are both relative to the character's
 */

#ifndef THE_STATISTICS_NORMALBRUSH_H
#define THE_STATISTICS_NORMALBRUSH_H

#include "Brush.h"

class NormalBrush : public Brush {
private:
    int size;
    
public:

    //Default constructor creates a brush of medium size
    //Everyone will start with a normal brush
    NormalBrush();

    //Setters
    void setColor(color colorIn);

    void setSize(int sizeIn);

    //Getters
    color getColor() const;

    int getSize() const;

    //Methods
    void changeColor();

};

#endif //THE_STATISTICS_NORMALBRUSH_H
