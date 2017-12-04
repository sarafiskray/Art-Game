//
// Created by Joshua on 11/18/2017.
//

#include "Map.h"
#include "Splatter.h"
#include <iostream>



Map::Map() {
    //Makes platforms a 100x100, or NUMCOLUMNxNUMROW
    platforms.resize(NUMCOLUMN, vector<int>(NUMROW, 0));
    //Make drawing a 100x100
    drawing.resize(NUMCOLUMN, vector<Splatter>(NUMROW, nullptr));

    //Make the bottom row full, at least
    for (int i = 0; i < NUMCOLUMN; i++ ) {
        platforms[i][NUMROW - 1] = 1;
    }
}

void Map::saveDrawing() const{
    ofstream fileIn(mapFile);

    if (fileIn) {
        cout << "File opened successfully" << endl;

        for (int i = 0; i < NUMCOLUMN; i ++ ) {
            for (int ii = 0; ii < NUMROW; ii ++) {
                if (drawing[i][ii] != nullptr) {
                    fileIn << drawing[i][ii].getFill().red;
                    fileIn << ";";
                    fileIn << drawing[i][ii].getFill().blue;
                    fileIn << ";";
                    fileIn << drawing[i][ii].getFill().green;
                    fileIn << ";";
                    fileIn << i;
                    fileIn << ";";
                    fileIn << ii;
                    fileIn << endl;
                }
            }
        }

        cout << "Drawing was saved to the file." << endl;
    }
}

void Map::loadDrawing() const {
    ifstream fileIn(mapFile);

    if (fileIn) {
        cout << "File opened successfully." << endl;

        int r, g, b;
        point loc;
        char junk;

        //Reads each part of the splatter in from a file, in this order: R; G; B; xLocation; yLocation
        while (fileIn.peek() != EOF) {
            fileIn >> r;
            fileIn >> junk;
            fileIn >> b;
            fileIn >> junk;
            fileIn >> g;
            fileIn >> junk;
            fileIn >> loc.x;
            fileIn >> junk;
            fileIn >> loc.y;

            //Puts a splatter in the place where we said it would be, of that fill
            drawing[loc.y][loc.x] = new Splatter(r, g, b, loc.x, loc.y);
        }

        cout << "File loaded into the drawings vector" << endl;
    }
}

void Map::clearDrawing() {
    drawing.resize(NUMCOLUMN, vector<Splatter>(NUMROW, nullptr));
    cout << "Drawing cleared" << endl;
}

bool Map::isBeneath(point p) {
    return (platforms[p.x][p.y] == 1);
}

void Map::drawArt() const{
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(0,0);
    // bottom left corner
    glVertex2i(position.x, position.y + height);
    // bottom right corner
    glVertex2i(position.x + width, position.y + height);
    // top right corner
    glVertex2i(position.x + width, position.y);
    glEnd();
}