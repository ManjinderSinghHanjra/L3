#include "CallbackFunctions.h"
#include "Text.h"

unsigned char keyboardKey;
char *specialKeyboardKey ="";
char *modifier="";

char *mouseButtonPressed="";
char *mouseState="";
int mouseX, mouseY;

char *view="";

extern int dim;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    displayTextAt(-130, -40, 0, "mouseButton: %s", mouseButtonPressed);
    displayTextAt(-130, -50, 0, "mouseButtonState: %s", mouseState);
    displayTextAt(-130, -60, 0, "mouseX: %d", mouseX);
    displayTextAt(-130, -70, 0, "mouseY: %d", mouseY);
    displayTextAt(-130, -80, 0, "keyboard key: %c", keyboardKey);
    displayTextAt(-130, -90, 0, "modifier: %s", modifier);
    displayTextAt(70, -90, 0, view);
    glFlush();
    glutSwapBuffers();
}

void idle()
{
    display();
}

/* This callback function is called whenever the window is resized or reshaped */

void reshape(int width, int height)
{
    //Width To Height Ratio
    float w2h = (height>0)? (float)width/height : 1;
    glViewport(0, 0, width, height);

    //Setting up the Viewing Matrix to Orthographic Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dim*w2h, +dim*w2h, -dim, +dim, -dim, +dim);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/* This callback function is called when there is no activity in the window */
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
        exit(0);
        break;
    }
    keyboardKey = key;
    glutPostRedisplay();
}


/* This callback function is called whenever a keyboard interrupt is encountered */
void specialKeyboard(int key, int state, int a)
{

    int currentModifier = glutGetModifiers();
    switch(currentModifier)
    {
    case GLUT_ACTIVE_SHIFT:
        modifier = "SHIFT";
        break;
    case GLUT_ACTIVE_CTRL:
        modifier = "CTRL";
        break;
    case GLUT_ACTIVE_ALT:
        modifier = "ALT";
        break;
    }
    switch(key)
    {
    case GLUT_KEY_F1:
        view = "perspective";
        break;
    case GLUT_KEY_F2:
        view = "orthographic";
        break;
    }
    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
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
