//
// Created by Joshua on 11/17/2017.
//

#include "Character.h"
#include "NormalBrush.h"
#include "DottedBrush.h"


Character::Character(Map mapIn) {
    fill = {0, 0, 0};
    width = 2;
    height = 2;
    NormalBrush norm;
    DottedBrush dot;
    brushes.push_back(dot);
    brushes.push_back(norm);
    //currentBrush = brushes[0];
    brushSelection = 0;

    horizontalMomentum = 0;
    verticalMomentum = 0;

    location.x = 60;
    location.y = 60;

    thisMap = mapIn;
};

Character::Character(color f, int xIn, int yIn) {
    //Character();
    fill = f;
    location.x = xIn;
    location.y = yIn;
}

Character::Character(point p) {
    location = p;
}

Character::Character(color f, point p){
    fill = f;
    location = p;
}

int Character::getHMomentum() const {
    return horizontalMomentum;
}

int Character::getVMomentum() const {
    return verticalMomentum;
}

point Character::getLocation() const {
    return location;
}

int Character::getX() const {
    return location.x;
}

int Character::getY() const {
    return location.y;
}

//To be implemented with graphics: character RGB
color Character::getcolor() const {
    return fill;
}

void Character::setHMomentum(int x) {
    horizontalMomentum = x;
}

void Character::setVMomentum(int x) {
    verticalMomentum = x;
}

void Character::setLocation(point p) {
    location = p;
}

void Character::setLocation(int xIn, int yIn) {
    location.x = xIn;
    location.y = yIn;
}

void Character::setcolor(color f) {
    fill = f;
}

void Character::setcolor(double r, double g, double b) {
    fill.red = r;
    fill.blue = b;
    fill.green = g;
}

void Character::be() {
    //If the character has any momentum to the left or right, make him move that way, but iterate down
    if (horizontalMomentum != 0) {
        if (horizontalMomentum > 0) {
            moveRight();
            horizontalMomentum--;
        }

        else {
            moveLeft();
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
        if (!thisMap.isBeneath(location)) {
            fall();
        }
    }

    //If the character is landed, it has no vertical momentum
    if (thisMap.isBeneath(location))  {
        verticalMomentum = 0;
    }

    //Now report where the character is
    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::changeBrush(int choice) {
    if (choice == 0) {
        if (brushSelection == brushes.size() - 1) {
            brushSelection = 0;
        }
        else {
            ++brushSelection;
        }
    }
    else {
        if (brushSelection == 0) {
            brushSelection = brushes.size() - 1;
        }
        else {
            brushSelection--;
        }
    }

    cout << "New Brush: " << brushes[brushSelection].getBrushName() << endl;
}

Brush Character::getBrush() const {
    return brushes[brushSelection];
}

void Character::moveLeft() {
    //So one doesn't go off the screen
    if (!(location.x == 0) && thisMap.isBeneath(location)) {
        location.x -= (horizontalMomentum) + 2;
        horizontalMomentum--;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::moveRight() {
    //So one doesn't go off the screen
    if (!(location.x == 500) && thisMap.isBeneath(location)) {
        location.x += (horizontalMomentum) + 2;
        horizontalMomentum++;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;

}

void Character::jump() {
    //Only works if you have something to jump off of
    if (thisMap.isBeneath(location)) {
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

void Character::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(location.x, location.y);
    // bottom left corner
    glVertex2i(location.x, location.y + height);
    // bottom right corner
    glVertex2i(location.x + width, location.y + height);
    // top right corner
    glVertex2i(location.x + width, location.y);
    glEnd();
}