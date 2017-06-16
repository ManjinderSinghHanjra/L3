#include "Junction.h"


void reclear()
{
    glClearColor(DEF_WHITE, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

/* Called every single frame */
void display()
{
    reclear();
    camera();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-1.0,-1.0, 0.0);
        glVertex3f(0.0,1.0,0.0);
        glVertex3f(1.0, -1.0, 0.0);
    glEnd();

    //glFlush();
    glutSwapBuffers();

    //handleError();
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
                float nearPlane = 1 / 10, farPlane = 1 * 10;
                gluPerspective(fov, 1, nearPlane, farPlane);
            }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/* Called when there's no interaction with the window and the event queue is empty */
void idle()
{
    display();
}


void camera(void)
{
  double Ex = -2*dim*Sin(theta)*Cos(phi);
  double Ey = +2*dim        *Sin(phi);
  double Ez = +2*dim*Cos(theta)*Cos(phi);
  /* camera/eye position, aim of camera lens, up-vector */
  gluLookAt(Ex+ecx,Ey,Ez+ecz , ecx,ecy,ecz , 0,Cos(phi),0);
}
