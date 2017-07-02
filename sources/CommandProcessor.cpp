#include "CommandProcessor.h"
#include <string.h>



/* TO DO:
 * I still haven't implemented the code to free all the portions of memory which I dynamically allocated.
.* Don't forget it. Otherwise, it may lead to memory leaks, and question of how significant the leaks would be will
 * completely depend upon the allocated Heap memory throughout the journey of the execution time.
 * So, beware!
 */

 /* EOF is an integer. So don't mistake to compare it with some char value */

void commandProcess(char *command)
{
    char *delim = " \t\f";
    char **tokens = (char**)malloc(1024);
    int i=0;

    /* Extracting tokens from command string */
    for(tokens[i] = strtok(command, delim); tokens[i] != NULL; tokens[i] = strtok(NULL, delim))
    {
       i++;
    }


    if(strcmp(tokens[0], "poly")==0)
    {
        if(strcmp(tokens[1], "V3")==0)
        {
            PolygonV3 *polygonV3 = (PolygonV3*)malloc(sizeof(PolygonV3));
            polygonV3->x[0]= atoi(tokens[3]);
            polygonV3->x[1]= atoi(tokens[3+3]);
            polygonV3->x[2]= atoi(tokens[3+6]);

            polygonV3->y[0]= atoi(tokens[4]);
            polygonV3->y[1]= atoi(tokens[4+3]);
            polygonV3->y[2]= atoi(tokens[4+6]);

            polygonV3->z[0]= atoi(tokens[5]);
            polygonV3->z[1]= atoi(tokens[5+3]);
            polygonV3->z[2]= atoi(tokens[5+6]);

            add(&record, tokens[1], tokens[2], polygonV3);  //Adding a new Polygon to the Record
        }
        else if(strcmp(tokens[1], "V4")==0)
        {
            PolygonV4 *polygonV4 = (PolygonV4*)malloc(sizeof(PolygonV4));
            polygonV4->x[0]= atoi(tokens[3]);
            polygonV4->x[1]= atoi(tokens[3+3]);
            polygonV4->x[2]= atoi(tokens[3+6]);
            polygonV4->x[3]= atoi(tokens[3+9]);

            polygonV4->y[0]= atoi(tokens[4]);
            polygonV4->y[1]= atoi(tokens[4+3]);
            polygonV4->y[2]= atoi(tokens[4+6]);
            polygonV4->y[3]= atoi(tokens[4+9]);

            polygonV4->z[0]= atoi(tokens[5]);
            polygonV4->z[1]= atoi(tokens[5+3]);
            polygonV4->z[2]= atoi(tokens[5+6]);
            polygonV4->z[3]= atoi(tokens[5+9]);

            add(&record, tokens[1], tokens[2], polygonV4);  //Adding a new Polygon to the Record
        }
    }
    else if(strcmp(tokens[0], "create"))
    {
        //Check the type of the token[2] variables
        Record *record = checkInRecord(tokens[2]);

        while(strcmp(tokens[i], "rX") || strcmp(tokens[i], "rY") || strcmp(tokens[i], "rZ") ||
              strcmp(tokens[i], "tX") || strcmp(tokens[i], "tY") || strcmp(tokens[i], "tZ"))
        {
            switch(record->poly_type)
            {
                case 0:     perror("Error: Object not found & hence the new Object can't be created.\n");
                            break;
                case 3:     PolygonV3 *polygon = malloc(sizeof(PolygonV3));
                            memcpy(polygon, record->Polygon.polygonV3, sizeof(record->Polygon.polygonV3));
                            add(&record, "V3", token[1], polygon);
                            break;
                case 4:     PolygonV4 *polygon = malloc(sizeof(PolygonV4));
                            memcpy(polygon, record->Polygon.polygonV3, sizeof(record->Polygon.polygonV3));
                            break;
                            add(&record, "V3", token[1], polygon);
                default:    perror("Error: Objects with sides more than 4 are not supported.\n");
                            break;
            }
        }
        if(str)
    }
}
