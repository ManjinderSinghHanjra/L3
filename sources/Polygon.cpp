#include "Polygon.h"
#include <string.h>

void copyFloatArray(float dest[], float src[])
{
    memcpy(dest, src, sizeof(float)*3);
}
