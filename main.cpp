//
// Created by Saraf Ray on 11/16/17.
//

#include "Brush.h"
#include "graphics.h"

#include <iostream>





using namespace std;

int main(int argc, char** argv) {

    graphicsPlay(argc, argv);
/*
    //Some arbitrary testing data
    point p = {30, 30};
    //I wanna say this is gray?
    color f = {.2, .2, .2};


    Character johnny;
    Character jackie(p);
    Character jimmy(f, p, dot);
    Character jenny(f, 15, 15);

    //Test Constructors
    cout << "Jackie location: " << jackie.getX() << "," << jackie.getY() << endl;
    cout << "Jimmy brush: " << jimmy.getBrush().getBrushName() << endl;

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
    johnny.be();

    //Other testing
    johnny.changeBrush();

    johnny.moveRight();
    johnny.moveRight();
    johnny.jump();

    //Test Fill
    color s = {.5, .5, .5};
    johnny.setcolor(s);
    cout << "Char color: R:" <<johnny.getcolor().red << " G:" << johnny.getcolor().green << " B:" << johnny.getcolor() << endl;
    johnny.setcolor(.1, .1, .1);
    cout << "Char color: R:" <<johnny.getcolor().red << " G:" << johnny.getcolor().green << " B:" << johnny.getcolor() << endl;

    //Test location
    johnny.setLocation(p);
    cout << "Char x location: " << johnny.getLocation().x << " and Y: " << johnny.getLocation().y << endl;
    johnny.setLocation(60, 60);
    cout << "Char x location: " << johnny.getLocation().x << " and Y: " << johnny.getLocation().y << endl;

    //Test getX and getY
    cout << "Char x location: " << johnny.getX() << endl;
    cout << "Char y location: " << johnny.getY() << endl;

    //Test Momentum
    johnny.setHMomentum(2);
    //Should be 2
    cout << "Char horizontal momentum (- -> + = L -> R): " << johnny.getHMomentum() << endl;
    johnny.setVMomentum(4);
    //Should be 4
    cout << "Char vertical momentum (- -> + = Down -> Up): " << johnny.getVMomentum() << endl;

    //Test Map methods

    johnny.thisMap.saveDrawing();
    johnny.thisMap.clearDrawing();
    johnny.thisMap.loadDrawing();

    cout << "is there something beneath (5, 99)? : " >> johnny.thisMap.isBeneath({5, 99});
*/

    return 0;
}