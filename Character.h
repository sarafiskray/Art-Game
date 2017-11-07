//
// Created by Andrew Ridgely on 11/7/17.
//

#ifndef THE_STATISTICS_CHARACTER_H
#define THE_STATISTICS_CHARACTER_H

struct skin {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Character {
private:
    skin fill;
    int speed;
public:
    point location;

    //constructors
    Character();
    Character(location p);
    Character(skin f);
    Character(int speed);
    Character(skin f, location p);


};


#endif //THE_STATISTICS_CHARACTER_H
