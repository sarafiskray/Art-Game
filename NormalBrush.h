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
            switch(colorChoice) {
                case (1):
                    //Make it red
                    color = (1, 0, 0);
                    cout << "Color switched to red." << endl;
                    break;
                case (2):
                    //Orange
                    color = (1, .64, 0);
                    cout << "Color switched to orange." << endl;
                    break;
                case (3):
                    //Yellow
                    color = (1, 1, 0);
                    cout << "Color switched to yellow." << endl;
                    break;
                case (4):
                    //Green
                    color = (0, .5, 0);
                    cout << "Color switched to green." << endl;
                    break;
                case (5):
                    //Blue
                    color = (0, 0, 1);
                    cout << "Color switched to blue." << endl;
                    break;
                case (6):
                    //Purple
                    color = (.29, 0, .5);
                    cout << "Color switched to purple." << endl;
                    break;
                case (7):
                    //Pink
                    color = (1, .75, .80);
                    cout << "Color switched to pink." << endl;
                    break;
                case (8):
                    //White
                    color = (1, 1, 1);
                    cout << "Color switched to white." << endl;
                    break;
                case (9):
                    //Gray
                    color = (.75, .75, .75);
                    cout << "Color switched to gray." << endl;
                    break;
                case (0):
                    //Black
                    color = (0, 0, 0);
                    cout << "Color switched to black." << endl;
                    break;
            }
        }
    }

};

#endif //THE_STATISTICS_NORMALBRUSH_H
