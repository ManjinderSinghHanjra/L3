#ifndef TEXT_H
#define TEXT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif // __APPLE__

void displayTextV(va_list args, const char* format);
void displayText(const char* format, ...);
void displayTextAt(int x, int y, int z, const char* format, ...);

#endif // TEXT_H
