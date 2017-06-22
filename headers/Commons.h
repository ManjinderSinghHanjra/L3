#ifndef COMMONS_H
#define COMMONS_H

#include <math.h>

#define DEF_WHITE 1.0, 1.0, 1.0
#define DEF_BLACK 0.0, 0.0, 0.0


/* Maths Macros */
#define PI 3.1415926
#define Cos(theta) cos((PI * theta) / 180)
#define Sin(theta) sin((PI * theta) / 180)

/* Projection defaults */
#define DEF_ASP 1
#define DEF_DIM 100
#define DEF_FOV 50
#define DEF_THETA 30
#define DEF_PHI 60
#define DEF_ECX 2
#define DEF_ECY 2
#define DEF_ECZ 2

#define DEF_NEAR  (1 / 10)
#define DEF_FAR  (1 * 10)



/* Draw defaults */
#define DEF_AXES 1
#define DEF_PARAMS 1
#define DEF_PROJ 1

/* Shape degrees */
#define DEF_DEGREES 5



#endif // COMMONS_H
