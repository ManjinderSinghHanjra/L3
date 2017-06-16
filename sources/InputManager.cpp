#include "InputManager.h"

void keyboard(unsigned char key, int x, int y)
{
    if(key==27) exit(0);
    else if(key == 'x' || key == 'X') toggleAxes = 1 - toggleAxes;
    else if (key == 'v' || key == 'V') toggleParameters = 1-toggleParameters;
    else if (key == 'p' || key == 'P') toggleProjection = 1-toggleProjection;
    /*  Change field of view angle */
    else if (key == '-' ) fov--;
    else if (key == '+' ) fov++;
    /*  Change dimensions */
    else if (key == 'D') dim += 0.2;
    else if (key == 'd') dim -= 0.2;
}

void mouse(int button, int state, int x, int y)
{

}

void mouseMotion(int x, int y)
{

}


void specialKeyboard(int button, int x, int y)
{

}
