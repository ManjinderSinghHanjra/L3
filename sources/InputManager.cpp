#include "InputManager.h"

void keyboard(unsigned char key, int x, int y)
{
    if(key==27) exit(0);
    else if(key == 'x' || key == 'X') toggleAxes = 1 - toggleAxes;
    else if (key == 'v' || key == 'V') toggleParameters = 1-toggleParameters;
    else if (key == 'p' || key == 'P') toggleProjection = 1-toggleProjection;
    /*  Change field of view angle */
    else if (key == '+' ) fov++;
    else if (key == '-' ) fov--;
    /*  Change dimensions */
    else if (key == '[') dim++;
    else if (key == ']') dim--;
    /*  Change viewing angles */
    else if (key == '6') theta = (theta + 1)%360;
    else if (key == '4') theta = (theta - 1)%360;
    else if (key == '8') phi = (phi + 1)%360;
    else if (key == '2') phi = (phi - 1)%360;
    /*  Change far and near planes */
    else if (key == '9') nearPlane += 0.1;
    else if (key == '0') farPlane -= 0.1;
    glutPostRedisplay();
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
