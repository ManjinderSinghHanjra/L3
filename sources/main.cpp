#include <GL/freeglut.h>
#include "Junction.h"

#define WIDTH 700
#define HEIGHT 400


/* Initialises the GLUT System, Creates a window, and Sets up the viewport */
void initDisplay(int *argc, char **argv, int width, int height)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("Project L3");
    glViewport(0, 0, width, height);
    //glutSwapBuffers();
}



int main(int argc, char** argv)
{
    setupGlobals();
    initDisplay(&argc, argv, WIDTH, HEIGHT);
    setupCallbackFunctions();
    glutMainLoop();
}


/*
 *  To-do:
 *      1. Rewrite displayText() function to handle any type of data.:: Done
 *      2. Add Perspective View :: Done
 */
