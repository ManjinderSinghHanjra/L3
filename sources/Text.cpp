#include "Text.h"

#define LEN 2048
void displayTextV(va_list args, const char* format)
{
    char buf[LEN];
    char* ch = buf;
    vsnprintf(buf, LEN, format, args);
    while(*ch)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *ch++);
}

void displayText(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    displayTextV(args, format);
    va_end(args);
}

void displayTextAt(int x, int y, int z, const char* format, ...)
{
    va_list args;
    glRasterPos3i(x, y, z);
    va_start(args, format);
    displayTextV(args, format);
    va_end(args);
}
