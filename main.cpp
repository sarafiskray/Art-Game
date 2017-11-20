//
// Created by Saraf Ray on 11/16/17.
//
#include "Character.h"
#include "Map.h"

using namespace std;

int main() {

    Character johnny;

    //Called with the left button in graphics or with A
    //Be is used on every refresh, and includes the fall() function, so will not fall until we call that
    //So it'll go left progressively faster but not fall at all
    johnny.moveLeft();
    johnny.moveLeft();
    johnny.moveLeft();
    johnny.be();

    //Be is called on every refresh, so technically it should be called far more times than this.
    //Because of that, this character will fall much slower than it will
    johnny.be();
    johnny.be();//good
    johnny.be();

    //Called by right button or D
    johnny.moveRight();

    //Called by up or W
    johnny.jump();

    johnny.be();
    jonny.be();

    //Other testing
    johnny.changeBrush();

    johnny.moveRight();
    johnny.moveRight();
    johnny.jump();

    //Should be 2
    cout << "Char horizontal momentum (- -> + = L -> R): " << johnny.getHMomentum() << endl;
    //Should be 4
    cout << "Char vertical momentum (- -> + = Down -> Up): " << johnny.getVMomentum() << endl;

    //These should both reflect the last location given by jump
    cout << "Char x location: " << johnny.getX() << endl;
    cout << "Char y location: " << johnny.getY() << endl;
    cout << "Char x location: " << johnny.getLocation().x << " and Y: " << johnny.getLocation().y << endl;


    return 0;
}