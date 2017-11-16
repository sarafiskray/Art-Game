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
    Brush currentBrush;
    vector<Brush> brushes;
public:
    point location;

    //constructors
    Character() {
        NormalBrush nb = brushes[0];
        DottedBrush db = brushes[1];
        currentBrush = brushes[0];
    };
    Character(location p);
    Character(skin f);
    Character(int speed);
    Character(Brush brush);
    Character(skin f, location p, Brush brush);


    void changeBrush() {
           for (int i = 0; i < brushes.size(); i++) {
               if (brushes[i] == currentBrush) {
                   currentBrush = brushes[i+1];
               }
           }
    }

    //getters

    //setters



};


#endif //THE_STATISTICS_CHARACTER_H
