/* This is the common access point to other cpp sources. Any file can include this to access other files. But don't forget to include guards to avoid cyclic-dependency. */

#ifndef JUNCTION_H
#define JUNCTION_H

#include <GL/freeglut.h>

#include "Commons.h"
#include "Globals.h"
#include "Display.h"
#include "InputManager.h"
#include "ErrorHandler.h"

void setupGlobals();
void setupCallbackFunctions();


/* Display.h */
extern void initDisplay(int *argc, char **argv, int width, int height);
extern void display();
extern void reshape(int width, int height);
extern void idle();

/* InputManager.h */
extern void keyboard(unsigned char key, int x, int y);
extern void specialKeyboard(int button, int x, int y);
extern void mouse(int button, int state, int x, int y);
extern void mouseMotion(int x, int y);

#endif // JUNCTION_H