//
// Created by Joshua on 11/17/2017.
//

#include "Character.h"
#include "Eraser.h"
#include "DottedBrush.h"


Character::Character(Map *mapIn) {
    fill = {0, 0, 0};
    width = 20;
    height = 20;
    //unique_ptr<NormalBrush> norm (new NormalBrush(mapIn));
    unique_ptr<DottedBrush> dot (new DottedBrush{mapIn});
    unique_ptr<Eraser> erase (new Eraser{mapIn});
    brushes.push_back(move(dot));
    brushes.push_back(move(erase));
    //brushes.push_back(move(norm));
    //currentBrush = brushes[0];
    brushSelection = 0;

    horizontalMomentum = 0;
    verticalMomentum = 0;

    location.x = 100;
    location.y = 400;

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
        location.y -= (verticalMomentum * 4);
        verticalMomentum--;
    }
        //if there is nothing underneath the character, then it calls the fall function
    else {
        if (!thisMap->isBeneath({location.x, location.y + 20})) {
            fall();
            verticalMomentum--;
        }
        else {
            verticalMomentum = 1;
        }
    }

    //If the character is landed, it has no vertical momentum
    if (thisMap->isBeneath({location.x, location.y + 20}))  {
        verticalMomentum = 0;
    }

    //Now report where the character is
    //cout << "Be: X: " << location.x << " Y: " << location.y << endl;

}

void Character::leftPress() {
    horizontalMomentum -= 3;
    if (horizontalMomentum < -5) {
        horizontalMomentum = -5;
    }
    moveLeft();
}

void Character::moveLeft() {
    //So one doesn't go off the screen
    if (!(location.x == 0) &&  (location.x - (horizontalMomentum * 2)) > 0) {
        location.x -= -(horizontalMomentum) * 2;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;
    getBrush().drawHere(location);

}

void Character::rightPress() {
    horizontalMomentum += 3;
    if (horizontalMomentum > 5) {
        horizontalMomentum = 5;
    }
    moveRight();
}

void Character::moveRight() {
    //So one doesn't go off the screen
    if (!(location.x == 500) &&  (location.x + (horizontalMomentum +2)) < 500) {
        location.x += (horizontalMomentum) * 2;
    }

    cout << "X: " << location.x << " Y: " << location.y << endl;
    getBrush().drawHere(location);

}

void Character::jump() {
    //Only works if you have something to jump off of
    if (thisMap->isBeneath({location.x, location.y+20})) {
        verticalMomentum += 10;

        //Character actually can go above the stage, so no special case
        cout << "Jumping! X: " << location.x << " Y: " << location.y << endl;
        getBrush().drawHere(location);
    }

}

void Character::fall() {

    location.y += 1 * -verticalMomentum;
    getBrush().drawHere(location);

    if (verticalMomentum < -4) {
        verticalMomentum = -4;
    }


    //If it falls through the floor, then put it back in the center. Shouldn't happen anyway
    if (location.y > 475) {
        location.y = 475;
        verticalMomentum = 0;
    }

    //cout << "Falling! X: " << location.x << " Y: " << location.y << endl;

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

    //cout << "New Brush: " << brushes[brushSelection]->getBrushName() << endl;
}

Brush& Character::getBrush() const {
    return *brushes[brushSelection];

}

void Character::changeColor(int choice) {
    getBrush().changeColor(choice);
    cout << "Color may have been changed" << endl;
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