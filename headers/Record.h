#ifndef RECORD_H
#define RECORD_H

#include "Polygon.h"

struct Record
{
    char *name;
    char *poly_type;
    PolygonV3 *polygonV3;
    PolygonV4 *polygonV4;
    Record *next;

    //void (*add)(Record **head_ref, char *name, void *polygon);
    //void (*print)(Record **head_ref);
};

void add(Record **head_ref, char *type, char *name, void *polygon);
void print(Record **head_ref);
#endif // RECORD_H
