#ifndef DISPLAY_H
#define DISPLAY_H

#include <Junction.h>

void initDisplay(int *argc, char **argv, int width, int height);

/* Display Interrupts callback functions */
void display();                                     //called every single frame
void reshape(int width, int height);                //called whenever the dimensions of the window are changed
void idle();                                        //when there is no interaction with the window

void camera();                                      //Camera/Eye

#endif // DISPLAY_H
