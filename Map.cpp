//
// Created by Joshua on 11/18/2017.
//

#include "Map.h"
#include "Splatter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "graphics.h"
#include <memory>

using namespace std;


Map::Map() {
    //Makes platforms a 100x100, or NUMCOLUMNxNUMROW
    platforms.resize(NUMCOLUMN, vector<int>(NUMROW, 0));
    drawing.resize(0);
    //Make the bottom row full, at least
    for (int i = 0; i < NUMCOLUMN; i++ ) {
        platforms[i][NUMROW-5] = 1;
    }

    savedDrawing = false;

}

void Map::addSplatter(Splatter splatIn) {
    drawing.push_back(splatIn);
}

void Map::setSaved() {
    savedDrawing = !savedDrawing;
}

void Map::saveDrawing(){
    ofstream fileIn(mapFile, ios::app);

    if (fileIn) {
        cout << "File opened successfully" << endl;

        for (Splatter splat : drawing) {
            fileIn << splat.getFill().red;
            fileIn << ";";
            fileIn << splat.getFill().blue;
            fileIn << ";";
            fileIn << splat.getFill().green;
            fileIn << ";";
            fileIn << splat.getX();
            fileIn << ";";
            fileIn << splat.getY();
            fileIn << ";";
            fileIn << splat.getSize();
            fileIn << endl;
        }

        cout << "Drawing was saved to the file." << endl;
        savedDrawing = true;
    }
}


void Map::loadDrawing() {
    ifstream fileIn(mapFile);

    if (fileIn) {
        cout << "File opened successfully." << endl;

        int r, g, b, size;
        point loc;
        char junk;

        //Reads each part of the splatter in from a file, in this order: R; G; B; xLocation; yLocation
        while (fileIn && fileIn.peek() != EOF) {
            fileIn >> r;
            fileIn >> junk;
            fileIn >> b;
            fileIn >> junk;
            fileIn >> g;
            fileIn >> junk;
            fileIn >> loc.x;
            fileIn >> junk;
            fileIn >> loc.y;
            fileIn >> junk;
            fileIn >> size;

            //Puts a splatter in the place where we said it would be, of that fill
            Splatter tempSplat = Splatter(r, g, b, loc.x, loc.y, size);
            drawing.push_back(tempSplat);

        }

        cout << "File loaded into the drawings vector" << endl;

    }
    else {
        cout <<"No drawings saved. None were loaded." << endl;
    }
}

void Map::clearDrawing() {
    drawing.clear();
    cout << "Drawing cleared" << endl;
}

bool Map::isBeneath(point p) {
    return (platforms[p.x][p.y] == 1);
}

void Map::drawArt() const{
    for (Splatter splat : drawing) {
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
        // top left corner
        glVertex2i(splat.getX(), splat.getY());
        // bottom left corner
        glVertex2i(splat.getX(), splat.getY()+5);
        // bottom right corner
        glVertex2i(splat.getX()+5, splat.getY()+5);
        // top right corner
        glVertex2i(splat.getX()+5, splat.getY());
        glEnd();
    }
}

void Map::drawMap() const {
    for (int x = 0; x < NUMCOLUMN; x++) {
        for (int y = 0; y < NUMROW; y++) {
            if (platforms[x][y] == 1) {
                glColor3f(.52, .12, .15);
                glBegin(GL_QUADS);
                // top left corner
                glVertex2i(x, y);
                // bottom left corner
                glVertex2i(x, y+5);
                // bottom right corner
                glVertex2i(x+1, y+5);
                // top right corner
                glVertex2i(x+1, y);
                glEnd();
            }
        }
    }
}