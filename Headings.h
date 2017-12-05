//
// Created by Joshua on 12/3/2017.
//

#ifndef THE_STATISTICS_HEADINGS_H
#define THE_STATISTICS_HEADINGS_H

struct point {
    int x;
    int y;
};

struct color {
    double red;
    double green;
    double blue;
};

color indigo = {.294, 0, .509};
color blue = {0, 0, 1};
color cyan = {0, 1, 1};
color green = {0, 1, 0};
color yellow = {1, 1, 0};
color gold = {1, .843, 0};
color orange = {1, .647, 0};
color pink = {1, .753, .796};
color red = {1, 0, 0};
color maroon = {.502, 0, 0};
color brown = {.627, .321, .176};
color gray = {.66, .66, .66};
color black = {0, 0, 0};

vector<color> colorPalette = {indigo, blue, cyan, green, yellow, gold, orange, pink, red, maroon, brown, gray, black};

#endif


