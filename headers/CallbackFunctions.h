#ifndef CALLBACKFUNCTIONS_H
#define CALLBACKFUNCTIONS_H

#include "GL/freeglut.h"

/* Hardware Interrupts callback functions */
void display();                                     //called every single frame
void reshape(int width, int height);                //called whenever the dimensions of the window are changed
void idle();                                        //when there is no interaction with the window
void keyboard(unsigned char key, int x, int y);     //whenever a keyboard key is pressed/interrupt occurs
void specialKeyboard(int button, int x, int y);     //captures special keys like: SHIFT ALT CTRL F1.....
void mouse(int button, int state, int x, int y);    //captures the mouse clicks and their state
void mouseMotion(int x, int y);                     //captures the motion of the mouse pointer in the window

#endif // CALLBACKFUNCTIONS_H
