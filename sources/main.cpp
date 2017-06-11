#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <GL/freeglut.h>
#include "Display.h"
#include "CallbackFunctions.h"

#define WIDTH 700
#define HEIGHT 400


// Dimension factor for Orthographic View
int dim = 100;



int main(int argc, char** argv)
{
    setupGlutWindow(&argc, argv, WIDTH, HEIGHT);
    setupCallbackFunctions();
    glutMainLoop();
}


/*
 *  To-do:
 *      1. Rewrite displayText() function to handle any type of data.:: Done
 *      2. Add Perspective View
 *      3.  w.r.t. Aspect Ratio
 */
