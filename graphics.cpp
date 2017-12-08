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
Rectangle start_background, playButton;
color playButtonText, playButtonColor;

//Game screen elements
Character saraf;
Map thisMap;
Rectangle legend;
bool displayLegend;




void init() {
    width = 500;
    height = 500;

    start_background.set_position(-10, -10);
    start_background.set_fill(1, 1, 1);
    start_background.set_dimensions(520, 520);

    Rectangle r1;
    playButton.set_position(300, 300);
    playButton.set_fill(0, 0, 0);
    playButton.set_dimensions(100, 50);
    playButtonText = whiteX;
    playButtonColor = blackX;

    displayLegend = false;
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
    thisMap.drawMap();
    saraf.draw();

    string message = "press p for legend";

    string legendHeader = "L E G E N D";
    string legend2 = "Arrow keys to move";
    string legend3 = "Press O to save the your drawing";
    string legend4 = "Press I to load your last drawing";
    string legend5 = "Press U to claer your drawing";
    string legend6 = "Press A or D to cycle through brush colors.";
    vector<string> legendTexts = {legendHeader, legend2, legend3, legend4, legend5, legend6};

    if (displayLegend) {
        legend.set_position(400, 20);
        legend.set_dimensions(80, 100);
        legend.set_fill(blackX)
        legend.draw();

        int yLoc = 30;
        for (string text : legendTexts) {
            draw_text(text, 1, 1, 1, 410, yLoc += 20);
        }

    }





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

    //Holding down the p button to get the legend
    if (screen == game && key == 112) {
        displayLegend = !displayLegend;
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            if (screen = game) {

            }

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

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
    }


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && playButton.is_overlapping(x, y)) {
        screen = game;
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
    wd = glutCreateWindow("Fun with Drawing!" /* title */ );

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