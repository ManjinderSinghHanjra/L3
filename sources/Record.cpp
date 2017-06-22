#include "Record.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

void add(Record **head_ref, char *type, char *name, void *polygon)
{
    Record *new_record = (Record *) malloc(sizeof(Record));
    new_record->name = name;
    new_record->poly_type = type;
    if(strcmp(type, "V3") == 0)
    {
        new_record->polygonV3 = (struct PolygonV3*)polygon;
        new_record->polygonV4 = NULL;
    }
    else
    {
        new_record->polygonV3 = NULL;
        new_record->polygonV4 = (struct PolygonV4*)polygon;
    }
    new_record->next = (*head_ref);
    (*head_ref) = new_record;
}


void print(Record **head_ref)
{
    while(*head_ref != NULL)
    {
        printf("[Record] : \n");
        printf("[Entity Name] : %s\n", (*head_ref)->name);
        printf("[Entity Type] : %s\n", (*head_ref)->poly_type);
        printf("[x1, y1, z1] : [%d, %d, %d]\n", (*head_ref)->polygonV3->x[0], (*head_ref)->polygonV3->y[0], (*head_ref)->polygonV3->z[0]);
        printf("[x2, y2, z2] : [%d, %d, %d]\n", (*head_ref)->polygonV3->x[1], (*head_ref)->polygonV3->y[1], (*head_ref)->polygonV3->z[1]);
        printf("[x3, y3, z3] : [%d, %d, %d]\n", (*head_ref)->polygonV3->x[2], (*head_ref)->polygonV3->y[2], (*head_ref)->polygonV3->z[2]);
        (*head_ref) = (*head_ref)->next;
    }
}
