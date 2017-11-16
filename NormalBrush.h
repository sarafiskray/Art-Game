//
// Created by Joshenberg
//

/*
 * Goals for this file:
 * A brush that is implemented normally. Has a single color, size
 * Its xPos and yPos are both relative to the character's
 */

#ifndef THE_STATISTICS_NORMALBRUSH_H
#define THE_STATISTICS_NORMALBRUSH_H

class NormalBrush : public Brush {
private:
    Color color;
    int size;
    
public:

    //Default constructor creates a white brush of medium size
    //Everyone will start with a normal brush
    NormalBrush() {
        color = (1, 1, 1);
        size = 2;
    }

    //Setters
    void setColor(Color colorIn) {
        color = colorIn;
    }

    void setSize(int sizeIn) {
        size = sizeIn;
    }

    //Getters
    Color getColor() const {
        return color;
    }

    int getSize() const {
        return size;
    }

    //Methods
    void changeColor(int colorChoice) {
        if (colorChoice > 9 || colorChoice < 0) {
            cout << "Invalid color input" << endl;
        }
        else {
            if (colorChoice == 1) {
                //Make it red
                color = (1, 0, 0);
            }
            else if (colorChoice == 2) {
                //Orange
                color = (1, .64, 0);
            }
            else if (colorChoice == 3) {
                //Yellow
                color = (1, 1, 0);
            }
            else if (colorChoice == 4) {
                //Green
                color = (0, .5, 0);
            }
            else if (colorChoice == 5) {
                //Blue
                color = (0, 0, 1);
            }
            else if (colorChoice == 6) {
                //Purple
                color = (.29, .64, 0);
            }
        }
    }

};

#endif //THE_STATISTICS_NORMALBRUSH_H
