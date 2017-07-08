#ifndef POLYGON_H
#define POLYGON_H

struct PolygonV3
{
    int x[3], y[3], z[3];
};

struct PolygonV4
{
    int x[4], y[4], z[4];
};


typedef struct PolygonV3 PolygonV3;
typedef struct PolygonV4 PolygonV4;


void copyFloatArray(float dest[], float src[]);

#endif // POLYGON_H
