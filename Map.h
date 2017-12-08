//
// Created by Saraf Ray on 11/7/17.
//

#ifndef THE_STATISTICS_MAP_H
#define THE_STATISTICS_MAP_H


#include "Splatter.h"
#include <vector>
using namespace std;
#include <string>
#include <memory>

class Map {

private:
    //Platform vector actually stores integers at each location in the 2D array. a
    vector< vector <int> > platforms;
    //drawing that character creates, also stored by coordinates
    vector<Splatter> drawing;
    //name of file
    string mapFile = "mapFile.txt";

    int NUMROW = 500;
    int NUMCOLUMN = 500;

public:

    //constructor, makes vectors 100x100 and initializes the map a bit
    Map();
    //maybe more constructors to come
    /*
     * saveDrawing
     * Requires: A valid mapFile
     * Modifies: Nothing, except the mapFile itself
     * Effects: Writes to mapFile the indeces of each Splatter
     */
    void saveDrawing();

    /*
     * loadDrawing
     * Requires: A valid mapFile
     * Modifies: drawing vector
     * Effects: Adds a splatter to drawing vector at the indeces found in the mapFile
     */
    void loadDrawing();
    /*
     * clearDrawing
     * Requires: Nothing
     * Modifies: drawing vector
     * Effects: Removes all of the splatters from the drawing vector
     */
    void clearDrawing();

    /*
     * isBeneath
     * Requires: point p, which is character location
     * Modifies: Nothing
     * Effects: Returns whether or not the coordinates directly below the player are filled
     */
    bool isBeneath(point p);

    /*
     * drawArt
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Draws the art saved in the drawing vector onto the canvas
     */
    void drawArt() const;

    /*
     * drawMap
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Draws the platforms saved in platforms onto the canvas
     */
    void drawMap() const;

};

#endif //THE_STATISTICS_MAP_H
