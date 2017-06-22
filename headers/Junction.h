#ifndef JUNCTION_H
#define JUNCTION_H

#include <GL/freeglut.h>

#include "Commons.h"
#include "Globals.h"
#include "Display.h"
#include "InputManager.h"
#include "ErrorHandler.h"
#include "Console.h"
#include "Shapes.h"
#include "Record.h"

void initializeGlobals();
void initializeCallbackFunctions();


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
