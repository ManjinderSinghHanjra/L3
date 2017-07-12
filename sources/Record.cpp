#include "Record.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add(Record **head_ref, Record *record)
{
        record->next = (*head_ref);
        (*head_ref) = record;
}


Record *searchRecord(Record **head_ref, char *name)
{
    Record *temp = (*head_ref);

    while((*head_ref) != NULL)
    {
        if(strcmp((*head_ref)->name, name) == 0)
        {
            Record *another_temp = (*head_ref);
            (*head_ref) = temp;
            return (another_temp);
        }
        (*head_ref) = (*head_ref)->next;
    }

    (*head_ref) = temp;
    return NULL;
}


// For Debug Purpose
void print(Record **head_ref)
{
    Record *temp = (*head_ref);
    while((*head_ref) != NULL)
    {
        printf("[Record] : \n");
        printf("[Entity Name] : %s\n", (*head_ref)->name);
        printf("[Entity Type] : %d\n", (*head_ref)->poly_type);
        printf("[x1, y1, z1] : [%d, %d, %d]\n", (*head_ref)->Polygon.polygonV3->x[0], (*head_ref)->Polygon.polygonV3->y[0], (*head_ref)->Polygon.polygonV3->z[0]);
        printf("[x2, y2, z2] : [%d, %d, %d]\n", (*head_ref)->Polygon.polygonV3->x[1], (*head_ref)->Polygon.polygonV3->y[1], (*head_ref)->Polygon.polygonV3->z[1]);
        printf("[x3, y3, z3] : [%d, %d, %d]\n", (*head_ref)->Polygon.polygonV3->x[2], (*head_ref)->Polygon.polygonV3->y[2], (*head_ref)->Polygon.polygonV3->z[2]);
        (*head_ref) = (*head_ref)->next;
    }
    (*head_ref) = temp;
}
