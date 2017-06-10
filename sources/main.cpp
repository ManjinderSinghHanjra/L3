#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <GL/freeglut.h>
#include "Text.h"

#define WIDTH 700
#define HEIGHT 400


unsigned char keyboardKey;
char *specialKeyboardKey="";
char *modifier="";

char *mouseButtonPressed="";
char *mouseState="";
int mouseX, mouseY;

// Dimension factor for Orthographic View
int dim = 100;


/* Callback functions declarations*/
void display();
void reshape(int w, int h);
void idle();
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

/* Drawing functions declarations*/
void initialiseOpenGL();
void drawAxes();
void showInformation();
void displayText(int posx, int posy, int posz, char* text);
void displayTextNumbers(int posx, int posy, int posz, int text);


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Project L3");

    glViewport(0, 0, WIDTH, HEIGHT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);
    glutMainLoop();
}


/* Display Callback Function */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    showInformation();

    displayTextAt(-130, 10, 0, "mouseButton: %s", mouseButtonPressed);
    displayTextAt(-130, -10, 0, "mouseButtonState: %s", mouseState);
    displayTextAt(-130, -30, 0, "mouseX: %d", mouseX);
    displayTextAt(-130, -50, 0, "mouseY: %d", mouseY);
    displayTextAt(-130, -70, 0, "keyboard key: %c", keyboardKey);
    displayTextAt(-130, -90, 0, "modifier: %s", modifier);

    drawAxes();

    glFlush();
    glutSwapBuffers();
}


/* This callback function is called whenever the window is resized or reshaped */
void reshape(int w, int h)
{
    //Width To Height Ratio
    float w2h = (h>0)? (float)w/h : 1;
    glViewport(0, 0, w, h);

    //Setting up the Viewing Matrix to Orthographic Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dim*w2h, +dim*w2h, -dim, +dim, -dim, +dim);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/* This callback function is called when there is no activity in the window */
void idle()
{
    display();
}


/* This callback function is called whenever a keyboard interrupt is encountered */
void keyboard(unsigned char key, int x, int y)
{
    if(key == 27) { exit(0); }
    keyboardKey = key;
    glutPostRedisplay();
}


void specialKeyboard(int key, int x, int y)
{
    int currentModifier = glutGetModifiers();
    switch(currentModifier)
    {
        case GLUT_ACTIVE_SHIFT: modifier = "SHIFT";
                                break;
        case GLUT_ACTIVE_CTRL: modifier = "CTRL";
                                break;
        case GLUT_ACTIVE_ALT: modifier = "ALT";
                                break;
    }
    glutPostRedisplay();
}


void mouse(int button, int state, int a, int b)
{
    if(button == GLUT_LEFT_BUTTON)
        mouseButtonPressed = "Left";
    else if(button == GLUT_RIGHT_BUTTON)
        mouseButtonPressed = "Right";

    if(state == GLUT_DOWN)
        mouseState = "down";
    else if(state == GLUT_UP)
        mouseState = "up";
}

void mouseMotion(int x, int y)
{
    mouseX = x;
    mouseY = y;
}


/*-----------------------------------------DRAWING FUNCTIONS----------------------------------------------*/


/* This function draws the XYZ-Axes. It'll tell us the orientation of the axes w.r.t to the camera/eye. */
void drawAxes()
{
    glLineWidth(10);
    glBegin(GL_LINES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(80, 60, 0);
        glVertex3f(110.0, 60.0, 0.0);
        glVertex3f(80, 60, 0);
        glVertex3f(80.0, 90.0, 0.0);
        glVertex3f(80, 60, 0);
        glVertex3f(80.0, 60.0, 30.0);
    glEnd();

    displayTextAt(110, 60, 0, "X");
    displayTextAt(80, 90, 0, "Y");
    displayTextAt(80, 60, 90, "Z");
}


void showInformation()
{
    char *info = "Project L3";
    displayTextAt(-130, 80, 0, info);
    info = "(Esc) to quit";
    displayTextAt(-130, 70, 0, info);
}



/*
 *  To-do:
 *      1. Rewrite displayText() function to handle any type of data.:: Done
 *      2. Add Perspective View
 *      3.  w.r.t. Aspect Ratio
 */
