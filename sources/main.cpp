#include <GL/freeglut.h>
#include "Junction.h"

#define WIDTH 700
#define HEIGHT 400

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
    /* Creating a Polygon List aka Record here */
    Record *record = NULL;
    char command[1024];

    gets(command);

    char *delim = " \t\f";
    char **tokens;
    int i=0;

    /* Extracting tokens from command string */
    for(tokens[i] = strtok(command, delim); tokens[i] != NULL; tokens[i] = strtok(NULL, delim))
    {
       i++;
    }

    /* Command Processor */
    if(strcmp(tokens[0], "poly")==0)
    {
        if(strcmp(tokens[1], "V3")==0)
        {
            PolygonV3 *polygonV3 = (PolygonV3*) malloc(sizeof(PolygonV3));
            polygonV3->x[0]= atoi(tokens[3]);
            polygonV3->x[1]= atoi(tokens[3+3]);
            polygonV3->x[2]= atoi(tokens[3+6]);

            polygonV3->y[0]= atoi(tokens[4]);
            polygonV3->y[1]= atoi(tokens[4+3]);
            polygonV3->y[2]= atoi(tokens[4+6]);

            polygonV3->y[0]= atoi(tokens[5]);
            polygonV3->y[1]= atoi(tokens[5+3]);
            polygonV3->y[2]= atoi(tokens[5+6]);

            printf("(x1, y1, z1) : (%s, %s, %s)\n", tokens[3], tokens[4], tokens[5]);
            printf("(x2, y2, z2) : (%s, %s, %s)\n", tokens[3+3], tokens[4+3], tokens[5+3]);
            printf("(x3, y3, z3) : (%s, %s, %s)\n", tokens[3+6], tokens[4+6], tokens[5+6]);
            add(&record, tokens[1], tokens[2], polygonV3);  //Adding a new Polygon to the Record
        }
        else if(strcmp(tokens[1], "V4")==0)
        {
            PolygonV4 *polygonV4 = (PolygonV4*) malloc(sizeof(PolygonV4));
            polygonV4->x[0]= atoi(tokens[3]);
            polygonV4->x[1]= atoi(tokens[3+3]);
            polygonV4->x[2]= atoi(tokens[3+6]);
            polygonV4->x[3]= atoi(tokens[3+9]);

            polygonV4->y[0]= atoi(tokens[4]);
            polygonV4->y[1]= atoi(tokens[4+3]);
            polygonV4->y[2]= atoi(tokens[4+6]);
            polygonV4->y[3]= atoi(tokens[4+9]);

            polygonV4->y[0]= atoi(tokens[5]);
            polygonV4->y[1]= atoi(tokens[5+3]);
            polygonV4->y[2]= atoi(tokens[5+6]);
            polygonV4->y[3]= atoi(tokens[5+9]);

            add(&record, tokens[1], tokens[2], polygonV4);  //Adding a new Polygon to the Record
        }

    }

    /* GLUT SYSTEM INITIALISATION */
    initializeGlobals();
    initializeDisplay(&argc, argv, WIDTH, HEIGHT);
    initializeCallbackFunctions();
    glutMainLoop();

}
