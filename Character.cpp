//
// Created by Joshua on 11/17/2017.
//

#include "Character.h"

Character::Character() {
    NormalBrush nb = brushes[0];
    DottedBrush db = brushes[1];
    currentBrush = brushes[0];

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
        for (horizontalMomentum; horizontalMomentum > 0; horizontalMomentum--) {
            moveRight(5 * horizontalMomentum);
        }
        for (horizontalMomentum; horizontalMomentum < 0; horizontalMomentum++) {
            moveLeft(5 * horizontalMomentum);
        }
    }
}

void Character::changeBrush() {
    if (brushSelection == brushes.size() - 1) {
        brushSelection = 0;
        currentBrush = brushes[0];
    }
    else {
        currentBrush = brushes[++brushSelection];
    }
}

void Character::moveLeft() {
    location.x -= (horizontalMomentum * 3) + 2;
    horizontalMomentum--;
}

void Character::moveRight() {
    location.x += (horizontalMomentum * 3) + 2;
    horizontalMomentum++;
}

void Character::jump() {
    verticalMomentum += 4;
    for (verticalMomentum; verticalMomentum > 0; verticalMomentum--) {
        location.y +=  verticalMomentum;
    }

}

void Character::fall() {
    if(!thisMap.getBeneath(location)) {

        verticalMomentum -= 4;
        for (verticalMomentum; verticalMomentum < 0; verticalMomentum++) {
            location.y += verticalMomentum;
        }
    }
}