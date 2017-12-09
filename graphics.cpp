//
// Created by Saraf Ray on 12/3/17.
//

#include "graphics.h"
#include "Shapes.h"
#include "Character.h"

GLdouble width, height;
int wd;
enum screen_type {start, game};

screen_type screen;

//Start screen elements
Rectangulo start_background, playButton;
color playButtonText, playButtonColor;

//Game screen elements
Map thisMap;
Character saraf = Character(thisMap);
Rectangulo game_background;

//The all important legend
Rectangulo legend;
bool displayLegend;
string legendHeader = "L E G E N D";
string legend2 = "Arrow keys to move";
string legend3 = "Press O to save the your drawing";
string legend4 = "Press I to load your last drawing";
string legend5 = "Press U to clear your drawing";
string legend6 = "Press A or D to cycle through brush colors";
string legend7 = "Press W or S to cycle through your brushes";
string legend8 = "Press Q to decrease brush size, E to increase";
string legend9 = "Press SPACE to toggle drawing";
vector<string> legendTexts = {legendHeader, legend2, legend3, legend4, legend5, legend6, legend7, legend8, legend9};

color currentColor;
Rectangulo currentColorDisplay, prevColorDisplay, nextColorDisplay;



void init() {

    currentColor = saraf.getBrush().getColor();

    width = 500;
    height = 500;

    start_background.set_position(-10, -10);
    start_background.set_fill(1, 1, 1);
    start_background.set_dimensions(520, 520);


    playButton.set_position(300, 300);
    playButton.set_fill(0, 0, 0);
    playButton.set_dimensions(100, 50);
    playButtonText = whiteX;
    playButtonColor = blackX;

    displayLegend = false;

    currentColorDisplay.set_dimensions(15, 15);
    currentColorDisplay.set_position(100, 20);

    prevColorDisplay.set_dimensions(12, 12);
    prevColorDisplay.set_position(86, 22);

    nextColorDisplay.set_dimensions(12, 12);
    nextColorDisplay.set_position(118, 22);

    game_background.set_dimensions(550, 550);
    game_background.set_fill(whiteX);
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Functions for the Menu Screen */

void display_start() {
    start_background.draw();
    string message = "A R T";
    glColor3f(0, 0, 0);
    glRasterPos2i(180, 180);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    playButton.draw();

    message = "play";
    glColor3f(playButtonText.red, playButtonText.blue, playButtonText.green);
    glRasterPos2i(320, 320);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}

void draw_text(string text, int r, int g, int b, int x, int y) {
    glColor3f(r, g, b);
    glRasterPos2i(x, y);
    for (int i = 0; i < text.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[i]);
    }
}

void display_game() {
    //This updates the map, in case we load a new save or clear everything
    game_background.draw();
    thisMap.drawMap();

    saraf.draw();

    currentColorDisplay.set_fill(currentColor);
    currentColorDisplay.draw();
    prevColorDisplay.set_fill(saraf.getBrush().getPrevColor());
    prevColorDisplay.draw();
    draw_text("A", 1, 1, 1, 87, 23);
    nextColorDisplay.set_fill(saraf.getBrush().getNextColor());
    nextColorDisplay.draw();
    draw_text("D", 1, 1, 1, 119, 23);
    draw_text("W", 0, 0, 0, 96, 40);
    //Change 120 if the alignment is off
    draw_text("S", 0, 0, 0, 120, 40);
    draw_text(saraf.getBrush().getBrushName(), 0, 0, 0, 100, 40);


    string message = "press p for legend";

    if (displayLegend) {
        legend.set_position(300, 20);
        legend.set_dimensions(190, 200);
        legend.set_fill(blackX);
        legend.draw();

        int yLoc = 30;
        for (string text : legendTexts) {
            draw_text(text, 1, 1, 1, 310, yLoc += 20);
        }
    }

    //If painting is toggled on, paint away!
    if (saraf.getBrush().getPainting()) {
        saraf.getBrush().draw(saraf.getLocation());
    }

    //Move saraf again if he's got any momentum
    saraf.be();

}


/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    thisMap.drawMap();

    switch(screen) {
        case start: display_start();
            break;
        case game: display_game();
            break;
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    //Press the p button to toggle the legend
    if (screen == game && key == 112) {
        displayLegend = !displayLegend;
    }

    //press w to change brush upwards
    if (screen == game && key == 119){
        saraf.changeBrush(0);
    }
    //press s to change brush downward
    if (screen == game && key == 115) {
        saraf.changeBrush(1);
    }
    //press a for previous color
    if (screen == game && key == 97) {
        saraf.getBrush().changeColor(1);
    }
    //press d for next color
    if (screen == game && key == 100) {
        saraf.getBrush().changeColor(0);
    }
    //press space to toggle painting
    if (screen == game && key == 32) {
        saraf.getBrush().togglePaint();
    }
    //press o to save your drawing
    if (screen == game && key == 111) {
        thisMap.saveDrawing();
    }
    //press i to load your drawing
    if (screen == game && key == 105) {
        thisMap.loadDrawing();
    }
    //press u to clear the drawing
    if (screen == game && key == 117) {
        thisMap.clearDrawing();
    }
    //press q to decrease brush size
    if (screen == game && key == 113) {
        saraf.getBrush().changeSize(1);
    }
    //pres e to increase brush size
    if (screen == game && key == 101) {
        saraf.getBrush().changeSize(0);
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            if (screen == game) {
                saraf.leftPress();
            }

            break;
        case GLUT_KEY_RIGHT:
            if (screen == game) {
                saraf.rightPress();
            }

            break;
        case GLUT_KEY_UP:
            if (screen == game) {
                saraf.jump();
            }
            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {
    if (screen == start) {
        if (playButton.is_overlapping(x, y)) {
            playButton.set_fill(whiteX);
            playButtonText = blackX;
        }
        else if (!playButton.is_overlapping(x, y)) {
            playButton.set_fill(blackX);
            playButtonText = whiteX;
        }
    }


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && playButton.is_overlapping(x, y)) {
        screen = game;
    }

    //if you click the next color on the display, it will move to the next one
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == game && nextColorDisplay.is_overlapping(x, y)) {
        saraf.changeBrush(0);
    }

    //similarly, if you click the previous color, it will also switch
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == game && nextColorDisplay.is_overlapping(x, y)) {
        saraf.changeBrush(1);
    }


        glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("A R T" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}