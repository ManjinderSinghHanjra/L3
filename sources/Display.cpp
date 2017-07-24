#include "Junction.h"


extern Record *head_ref;
extern char user_command[];


void resetBuffers()
{
    // For Debugging Purpose
    //showInfoOnConsole();

    glClearColor(DEF_WHITE, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
}

/* Called every single frame */
void display()
{
    resetBuffers();
    setCamera();

    drawAllPolygons(&head_ref);

    glFlush();
    glutSwapBuffers();

    //handleError(): To be done
}


/* Called whenever the window's dimensions change */
void reshape(int w, int h)
{
    float w2h = (h>0)? (double)w/h: 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(toggleProjection == 0)
        glOrtho(-dim*w2h, +dim*w2h, -dim, +dim, -dim, +dim);
    else
    {
        gluPerspective(fov, 1, nearPlane, farPlane);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutPostRedisplay();
}


/* Called when there's no interaction with the window and the event queue is empty */
void idle()
{
    glutPostRedisplay();
}


void setCamera(void)
{
    double Ey = -2*dim*Sin(theta)*Cos(phi);
    double Ex = +2*dim        *Sin(phi);
    double Ez = +2*dim*Cos(theta)*Cos(phi);
    /*           camera/eye position[3],     aim of camera lens[3],   up-vector[3] */
    gluLookAt(   Ex+ecx,Ey,Ez+ecz,           ecx,ecy,ecz,             0,Cos(phi),0    );
}



void drawAllPolygons(Record **head_ref)
{
    Record *temp = (*head_ref);
    if((*head_ref) == NULL)
    {
        printf("Error: drawAllPolygons(), record = NULL\n");
        return;
    }
    while((*head_ref) != NULL)
    {
        if((*head_ref)->poly_type == 3)
        {
            glColor3f(0, 1, 0);
            glBegin(GL_TRIANGLES);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[0], (*head_ref)->Polygon.polygonV3->y[0], (*head_ref)->Polygon.polygonV3->z[0]);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[1], (*head_ref)->Polygon.polygonV3->y[1], (*head_ref)->Polygon.polygonV3->z[1]);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[2], (*head_ref)->Polygon.polygonV3->y[2], (*head_ref)->Polygon.polygonV3->z[2]);
            glEnd();
        }
        else if((*head_ref)->poly_type == 4)
        {
            glColor3f(0, 1, 0);
            glBegin(GL_QUADS);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[0], (*head_ref)->Polygon.polygonV3->y[0], (*head_ref)->Polygon.polygonV3->z[0]);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[1], (*head_ref)->Polygon.polygonV3->y[1], (*head_ref)->Polygon.polygonV3->z[1]);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[2], (*head_ref)->Polygon.polygonV3->y[2], (*head_ref)->Polygon.polygonV3->z[2]);
            glVertex3i((*head_ref)->Polygon.polygonV3->x[3], (*head_ref)->Polygon.polygonV3->y[3], (*head_ref)->Polygon.polygonV3->z[3]);
            glEnd();
        }
        (*head_ref) = (*head_ref)->next;
    }
    (*head_ref) = temp;
}
