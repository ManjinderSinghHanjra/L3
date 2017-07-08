#include <GL/freeglut.h>
#include "Junction.h"

#define WIDTH 700
#define HEIGHT 400

/* Creating a Polygon List / a Polygon Record here */
Record *record = NULL;

/* Initialises the GLUT System, Creates a window, and Sets up the Viewport */
void initializeDisplay(int *argc, char **argv, int width, int height)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Project L3");
    glViewport(0, 0, width, height);
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    char filename[FILENAME_MAX];

    /* There are cautions about fgets(), refer its documentation */
    fgets(filename, FILENAME_MAX, stdin);

    filename[strlen(filename)-1] = '\0';

    /* arg to fileprocess is  hard-coded here, replace it with filename */
    fileProcess("C:\\Users\\sos\\Documents\\Code Blocks c++\\L6\\src\\polygon.txt");

    /* For debugging purpose */
    print(&record);

    getc(stdin);

    /* GLUT SYSTEM INITIALISATION */
    initializeGlobals();
    initializeDisplay(&argc, argv, WIDTH, HEIGHT);
    initializeCallbackFunctions();
    glutMainLoop();
}
