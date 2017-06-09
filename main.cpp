#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <GL/freeglut.h>


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
void mouse(int x, int y, int a, int b);
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
    //glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);
    glutMainLoop();
}


/* Display Callback Function */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    showInformation();

    displayTextNumbers(-90, -30, 0, mouseX);
    displayTextNumbers(-90, -50, 0, mouseY);
    displayTextNumbers(-90, -90, 0, keyboardKey);
    displayText(-80, -70, 0, modifier);

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
    }
    glutPostRedisplay();
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

    displayText(110, 60, 0, "X");
    displayText(80, 90, 0, "Y");
    displayText(80, 60, 90, "Z");
}


void showInformation()
{
    char *info = "Project L3";
    displayText(-130, 80, 0, info);
    info = "(Esc) to quit";
    displayText(-130, 70, 0, info);
    info = "keyPressed: ";
    displayText(-130, -90, 0, info);
    info = "specialKeyPressed: ";
    displayText(-130, -70, 0, info);
    info = "mouseX: ";
    displayText(-130, -50, 0, info);
    info = "mouseY: ";
    displayText(-130, -30, 0, info);
}


void displayText(int posx, int posy, int posz, char *text)
{
    glRasterPos3i(posx, posy, posz);
    while(*text != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text);
        text++;
    }
}

void displayTextNumbers(int posx, int posy, int posz, int text)
{
    glRasterPos3i(posx, posy, posz);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text);
}

/*
 *  To-do:
 *      1. Rewrite displayText() function to handle any type of data.
 *      2. Add Perspective View
 */
