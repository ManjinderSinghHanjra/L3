#include "Junction.h"




void setupCallbackFunctions()
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
}


void setupGlobals()
{
    aspectRatio = DEF_ASP;
    dim = DEF_DIM;
    fov = DEF_FOV;
    theta = DEF_THETA;
    phi = DEF_PHI;
    ecx = DEF_ECX;
    ecy = DEF_ECY;
    ecz = DEF_ECZ;

    toggleAxes = DEF_AXES;
    toggleParameters = DEF_PARAMS;
    toggleProjection = DEF_PROJ;

    degreeRot = DEF_DEGREES;

}