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

struct Point {
    int x;
    int y;
};

class Character {
private:
    skin fill;
    int speed;
    Brush currentBrush;
    vector<Brush> brushes;
    Point location;

    //Two Momentums for controlling how the character responds and keeps moving after the player is not still running
    int horizontalMomentum;
    int verticalMomentum;

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

    //Returns struct Point with X and Y
    Point getLocation() const;
    //Returns x of location
    int getX() const;
    //Returns y of location
    int getY() const;


    //setters


    //Methods
    //Controls the character if the player is not pressing anything; lets momentum do most of the work. Also calls getBeneath()
    void be();

    void moveLeft();
    void moveRight();
    void jump();


};


#endif //THE_STATISTICS_CHARACTER_H
