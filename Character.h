//
// Created by Andrew Ridgely on 11/7/17.
//

#ifndef THE_STATISTICS_CHARACTER_H
#define THE_STATISTICS_CHARACTER_H


//Josh and Saraf the character will be a rectangle to make it
//easier for collosion detection. Maybe we can draw a character
//inside rectangle to have it look like a person
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
public:
    point location;

    //constructors
    Character() {
        NormalBrush nb = brushes[0];
        DottedBrush db = brushes[1];
        currentBrush = brushes[0];
    };

    Character(location p);
    Character(skin f, location p, Brush brush);
    Character(skin f, int xIn, int yIn);

    //Destructor
    ~Character();


    //getters

    //Returns struct Point with X and Y
    Point getLocation() const;
    //Returns x of location
    int getX() const;
    //Returns y of location
    int getY() const;
    //gets size of character
    double getArea() const;
    //gets color of character
    color getSkin() const;
    int getHMomentum() const;
    int getVMomentum() const;

    //setters
    void setSkin(skin f);
    void setSkin(double r, double g, double b);
    void setLocation(location p);
    void setLocation(int xIn, int yIn);
    void setHMomentum(int x);
    void setVMomentum(int x);



    //Methods
    //Controls the character if the player is not pressing anything; lets momentum do most of the work. Also calls getBeneath()
    void be();
    void changeBrush();
    //character moves left and right on x axis
    void moveLeft();
    void moveRight();
    //character changes position on y axis
    void jump();
    

private:
    skin fill;
    int speed;
    double width;
    double height;
    Brush currentBrush;
    vector<Brush> brushes;

    //Two Momentums for controlling how the character responds and keeps moving after the player is not still running
    int horizontalMomentum;
    int verticalMomentum;


};


#endif //THE_STATISTICS_CHARACTER_H
