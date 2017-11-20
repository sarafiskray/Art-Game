//
// Created by Joshua on 11/18/2017.
//

#include "Map.h"

Map::Map() {
    //Makes platforms a 100x100, or NUMCOLUMNxNUMROW
    platforms.resize(NUMCOLUMN, vector<int>(NUMROW, 0));
    //Make drawing a 100x100
    drawings.resize(NUMCOLUMN, vector<Splatter>(NUMROW, nullptr));

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
                if (drawings[i][ii] != nullptr) {
                    fileIn << drawings[i][ii].fill.red;
                    fileIn << ";";
                    fileIn << drawings[i][ii].fill.blue;
                    fileIn << ";";
                    fileIn << drawings[i][ii].fill.green;
                    fileIn << ";";
                    fileIn << i;
                    fileIn << ";";
                    fileIn << ii;
                    fileIn << endl;
                }
            }
        }
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
        }

        //Puts a splatter in the place where we said it would be, of that fill
        drawing[loc.y][loc.x] = new Splatter(r, g, b);
    }
}

void Map::clearDrawing() {
    drawings.resize(10, vector<Splatter>(10, nullptr));
}

bool Map::isBeneath(point p) {
    return (platforms[p.x][p.y] == 1);
}