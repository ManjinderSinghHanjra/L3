#include "Junction.h"


void initializeCallbackFunctions()
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
}


void initializeGlobals()
{
    aspectRatio = DEF_ASP;
    dim = DEF_DIM;
    fov = DEF_FOV;
    theta = DEF_THETA;
    phi = DEF_PHI;
    ecx = DEF_ECX;
    ecy = DEF_ECY;
    ecz = DEF_ECZ;

    nearPlane = DEF_NEAR;
    farPlane = DEF_FAR;

    toggleAxes = DEF_AXES;
    toggleParameters = DEF_PARAMS;
    toggleProjection = DEF_PROJ;

    degreeRot = DEF_DEGREES;
}
