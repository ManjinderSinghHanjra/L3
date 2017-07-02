#include "Record.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

void add(Record **head_ref, char *type, char *name, void *polygon)
{
    Record *new_record = (Record*)malloc(sizeof(Record));
    new_record->name = name;
    if(strcmp(type, "V3") == 0)
    {
        new_record->poly_type = 3;
        new_record->Polygon.polygonV3 = (PolygonV3*)polygon;
    }
    else
    {
        new_record->poly_type = 4;
        new_record->Polygon.polygonV4 = (PolygonV4*)polygon;
    }
    new_record->next = (*head_ref);
    (*head_ref) = new_record;

    if((*head_ref)->Polygon.polygonV4 != NULL)
        printf("NULL found\n");
}


Record *searchRecord(char *name)
{
    if(   )
    {
        return ;     //record_pointer;  It's completely valid since all we have to do is fetch a Record List, which is Global and return an exact pointer to the node
                    //                   that contains the result
    }
    return NULL;        // means not present
}


// For Debug Purpose
void print(Record **head_ref)
{
    while((*head_ref) != NULL)
    {
        printf("[Record] : \n");
        printf("[Entity Name] : %s\n", (*head_ref)->name);
        printf("[Entity Type] : %d\n", (*head_ref)->poly_type);
        printf("[x1, y1, z1] : [%d]\n", (*head_ref)->Polygon.polygonV3->x[0]);//, (*head_ref)->Polygon.polygonV3->y[0], (*head_ref)->Polygon.polygonV3->z[0]);
        printf("[x2, y2, z2] : [%d]\n", (*head_ref)->Polygon.polygonV3->x[1]);//, (*head_ref)->Polygon.polygonV3->y[1], (*head_ref)->Polygon.polygonV3->z[1]);
        printf("[x3, y3, z3] : [%d]\n", (*head_ref)->Polygon.polygonV3->x[2]);//, (*head_ref)->Polygon.polygonV3->y[2], (*head_ref)->Polygon.polygonV3->z[2]);
        (*head_ref) = (*head_ref)->next;
    }
}
