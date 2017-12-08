//
// Created by Andrew Ridgely on 11/7/17.
//

#ifndef THE_STATISTICS_CHARACTER_H
#define THE_STATISTICS_CHARACTER_H

#include "Brush.h"
#include "Map.h"
#include <vector>
#include "graphics.h"
#include "Headings.h"


//Josh and Saraf the character will be a rectangle to make it
//easier for collosion detection. Maybe we can draw a character
//inside rectangle to have it look like a person

//color really ought to be called fill, but we were thinking about character colors in video games while writing this
//We are not racist

class Character {
public:
    //Map the character is operating within
    Map thisMap;
    point location;
    color myColor;

    //constructors
    Character();

    Character(point p);
    Character(color f, point p);
    Character(color f, int xIn, int yIn);


    //getters

    //Returns struct Point with X and Y
    point getLocation() const;
    //Returns x of location
    int getX() const;
    //Returns y of location
    int getY() const;
    //gets color of character
    color getcolor() const;
    int getHMomentum() const;
    int getVMomentum() const;
    Brush getBrush() const;

    //setters
    //No setBrush because that is where we use changeBrush
    void setcolor(color f);
    void setcolor(double r, double g, double b);
    void setLocation(point p);
    void setLocation(int xIn, int yIn);
    void setHMomentum(int x);
    void setVMomentum(int x);



    //Methods
    /*
     * be
     * Requires: Nothing
     * Modifies: location.x, location.y, horizontalMomentum, verticalMomentum
     * Effects: A method for the player to keep moving even if a direction isn't pressed, based on momentum
     */
    void be();
    /*
     * changeBrush
     * Requires: Nothing
     * Modifies: currentBrush, brushSelection
     * Effects: currentBrush changes to the next in the vector. brushSelection iterates up, or back to 0 if it reaches brushes.size()
     */
    void changeBrush(int choice);
    /*
     * moveLeft
     * Requires: Nothing
     * Modifies: location.x, horizontalMomentum
     * Effects: moves the character left by an amount determined by character's momentum, increases horizontalMomentum
     */
    void moveLeft();
    /*
     * moveRight
     * Requires: Nothing
     * Modifies: location.x, horizontalMomentum
     * Effects: moves the character right by an amount determined by its momentum, increases horizontalMomentum
     */
    void moveRight();
    /*
     * jump
     * Requires: Nothing, but requires thisMap.isBeneath() to return true to actually jump. Otherwise, what are you jumping off of?
     * Modifies: location.y, verticalMomentum
     * Effects: moves the character up by an amount determined by its momentum, increases verticalMomentum
     */
    void jump();
    /*
     * fall
     * Requires: Nothing (but fully calling it requires thisMap.isBeneath() to return false. Can't fall through things
     * Modifies: location.y, verticalMomentum
     * Effects: moves the character down based on momentum, until it hits the ground. Decreases verticalMomentum.
     */
    void fall();

    void draw() const;
    

private:
    color fill;
    int speed;
    double width;
    double height;
    //Brush currentBrush;
    vector<Brush> brushes;

    //Two Momentums for controlling how the character responds and keeps moving after the player is not still running
    int horizontalMomentum;
    int verticalMomentum;



    //An index of the current brush, for use in the changeBrush method
    int brushSelection;


};


#endif //THE_STATISTICS_CHARACTER_H
