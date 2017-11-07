//
// Created by Saraf Ray on 11/7/17.
//

#ifndef THE_STATISTICS_MAP_H
#define THE_STATISTICS_MAP_H

class Map {
public:
    //platforms on map that character can stand on
    vector<Platform> platforms;
    //drawing that character creates
    vector<Splatter> drawing;
    //name of file
    string mapFile;
    //constructor
    Map();
    //maybe more constructors to come
    //method to save drawing
    void saveDrawing() const;
    //method to load drawing from file
    void loadDrawing() const;
    //method to clear existing drawing
    void clearDrawing();


};

#endif //THE_STATISTICS_MAP_H
