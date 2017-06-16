#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Junction.h"


void keyboard(unsigned char key, int x, int y);     //whenever a keyboard key is pressed/interrupt occurs
void specialKeyboard(int button, int x, int y);     //captures special keys like: SHIFT ALT CTRL F1.....
void mouse(int button, int state, int x, int y);    //captures the mouse clicks and their state
void mouseMotion(int x, int y);                     //captures the motion of the mouse pointer in the window

#endif // INPUTMANAGER_H
