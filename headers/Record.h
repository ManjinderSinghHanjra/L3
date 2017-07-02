#ifndef RECORD_H
#define RECORD_H

#include "Polygon.h"

#undef print

struct Record
{
    char *name;
    int poly_type;
    union {
        PolygonV3 *polygonV3;
        PolygonV4 *polygonV4;
    }Polygon;
    Record *next;

    //void (*add)(Record **head_ref, char *name, void *polygon);
    //void (*print)(Record **head_ref);
};

typedef struct Record Record;

void add(Record **head_ref, char *type, char *name, void *polygon);

void searchRecord(Record *record);

void print(Record **head_ref);
#endif // RECORD_H
