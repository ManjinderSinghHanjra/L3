#include "ErrorHandler.h"

void handleError()
{
    int error = glGetError();
    if(error != GL_NO_ERROR)
    {
        fprintf(stderr, "Error: %s\n", gluErrorString(error));
    }
}
