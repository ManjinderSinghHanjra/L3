#include "Display.h"

void setupGlutWindow(int *argc, char **argv, int width, int height)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Project L3");
    glViewport(0, 0, width, height);
}

void setupCallbackFunctions()
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);
}
