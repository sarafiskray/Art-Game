//
// Created by Saraf Ray on 11/16/17.
//
#include "Character.h"
#include "Map.h"

using namespace std;

int main() {

    Character johnny;

    johnny.moveLeft();
    johnny.moveLeft();
    johnny.be();

    //Be is called on every refresh, so technically it should be called far more times than this.
    //Because of that, this character will fall much slower than it will
    johnny.be();
    johnny.be();//good

    johnny.jump();

    return 0;
}