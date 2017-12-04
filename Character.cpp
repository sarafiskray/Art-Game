//
// Created by Joshua on 11/17/2017.
//

#include "Character.h"
#include "Brush.h"
#include "NormalBrush.h"
#include "DottedBrush.h"


Character::Character() {
    fill = {0, 0, 0};
    width = 2;
    height = 2;
    brushes = {new DottedBrush, new NormalBrush};
    currentBrush = brushes[0];
    brushSelection = 0;

    horizontalMomentum = 0;
    verticalMomentum = 0;

    location.x = 60;
    location.y = 60;

    thisMap = new Map();
};

Character::Character(skin f, int xIn, int yIn) {
    Character();

    fill = f;
    location.x = xIn;
    location.y = yIn;
}

Character::Character(point p) {
    location = p;
}

Character::Character(skin f, point p, Brush brush){
    fill = f;
    location = p;
    currentBrush = brush;
}



int Character::getHMomentum() const {
    return horizontalMomentum;
}

int Character::getVMomentum() const {
    return verticalMomentum;
}

Point Character::getLocation() const {
    return location;
}

int Character::getX() const {
    return location.x;
}

int Character::getY() const {
    return location.y;
}

//To be implemented with graphics: character RGB
color Character::getSkin() const {
    return skin;
}

Brush Character::getBrush() const {
    return currentBrush;
}

void Character::setHMomentum(int x) {
    horizontalMomentum = x;
}

void Character::setVMomentum(int x) {
    verticalMomentum = x;
}

void Character::setLocation(Point p) {
    location = p;
}

void Character::setLocation(int xIn, int yIn) {
    location.x = xIn;
    location.y = yIn;
}

void Character::setSkin(skin f) {
    skin = f;
}

void Character::setSkin(double r, double g, double b) {
    fill.red = r;
    fill.blue = b;
    fill.green = g;
}

void Character::be() {
    //If the character has any momentum to the left or right, make him move that way, but iterate down
    if (horizontalMomentum != 0) {
        if (horizontalMomentum > 0) {
            moveRight(5 * horizontalMomentum);
            horizontalMomentum--;
        }

        else {
            moveLeft(5 * -horizontalMomentum);
            horizontalMomentum++;
        }
    }

    //If the player has upward momentum, it moves up proportional to the momentum and then decreases that
    if (verticalMomentum > 0) {
        location.y += (verticalMomentum * 3);
        verticalMomentum--;
    }
        //if there is nothing underneath the character, then it calls the fall function
    else {
        if (!thisMap.isBeneath()) {
            fall();
        }
    }

    //If the character is landed, it has no vertical momentum
    if (thisMap.isBeneath())  {
        verticalMomentum = 0;
    }

    //Now report where the character is
    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::changeBrush() {
    if (brushSelection == brushes.size() - 1) {
        brushSelection = 0;
        currentBrush = brushes[0];
    }
    else {
        currentBrush = brushes[++brushSelection];
    }

    cout << "New Brush: " << currentBrush.getBrush << endl;
}

void Character::moveLeft() {
    //So one doesn't go off the screen
    if (!location.x == 0) {
        location.x -= (horizontalMomentum * 3) + 2;
        horizontalMomentum--;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::moveRight() {
    //So one doesn't go off the screen
    if (!location.x == 100) {
        location.x += (horizontalMomentum * 3) + 2;
        horizontalMomentum++;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::jump() {
    //Only works if you have something to jump off of
    if (thisMap.isBeneath()) {
        verticalMomentum += 4;
        location.y -= 4;

    }

    //Character actually can go above the stage, so no special case

    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::fall() {

    location.y += 4 * -verticalMomentum;
    verticalMomentum--;

    //If it falls through the floor, then put it back in the center. Shouldn't happen anyway
    if (location.y > 100) {
        location.x = 50;
        location.y = 50;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;

}