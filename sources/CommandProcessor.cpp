#include "CommandProcessor.h"
#include <stdlib.h>
#include <string.h>


/* TO DO:
 * I still haven't implemented the code to free all the portions of memory which I dynamically allocated on the heap.
.* So, beware!
 */

/* EOF is an integer. So don't mistake to compare it with some non-integer value otherwise results will be different. */


char *set_of_commands[] =
{
    // Creates a polygon
    "poly",

    // Duplicates a polygon, and applies transformations if required
    "create",

    // Changes the transformation of an already existing polygon
    "transform",

    // Creates an assembly of different polygon specified under the command
    "assemble",

    // Makes any side of any polygon extrude into the direction and value specified by the user
    "extrude"
};



void poly(char **tokens)
{
    Record *temp_record = (Record*)malloc(sizeof(Record));
    if(strcmp(tokens[1], "V3") == 0)
    {
        temp_record->Polygon.polygonV3 = (PolygonV3*)malloc(sizeof(PolygonV3));

        temp_record->poly_type = V3;
        temp_record->name = tokens[2];
        temp_record->Polygon.polygonV3->x[0]= atoi(tokens[3]);
        temp_record->Polygon.polygonV3->x[1]= atoi(tokens[3+3]);
        temp_record->Polygon.polygonV3->x[2]= atoi(tokens[3+6]);

        temp_record->Polygon.polygonV3->y[0]= atoi(tokens[4]);
        temp_record->Polygon.polygonV3->y[1]= atoi(tokens[4+3]);
        temp_record->Polygon.polygonV3->y[2]= atoi(tokens[4+6]);

        temp_record->Polygon.polygonV3->z[0]= atoi(tokens[5]);
        temp_record->Polygon.polygonV3->z[1]= atoi(tokens[5+3]);
        temp_record->Polygon.polygonV3->z[2]= atoi(tokens[5+6]);

        add(&head_ref, temp_record);
    }
    else if(strcmp(tokens[1], "V4") == 0)
    {
        temp_record->Polygon.polygonV4 = (PolygonV4*)malloc(sizeof(PolygonV4));

        temp_record->poly_type = V4;
        temp_record->name = tokens[2];

        temp_record->Polygon.polygonV4->x[0]= atoi(tokens[3]);
        temp_record->Polygon.polygonV4->x[1]= atoi(tokens[3+3]);
        temp_record->Polygon.polygonV4->x[2]= atoi(tokens[3+6]);
        temp_record->Polygon.polygonV4->x[3]= atoi(tokens[3+9]);

        temp_record->Polygon.polygonV4->y[0]= atoi(tokens[4]);
        temp_record->Polygon.polygonV4->y[1]= atoi(tokens[4+3]);
        temp_record->Polygon.polygonV4->y[2]= atoi(tokens[4+6]);
        temp_record->Polygon.polygonV4->y[3]= atoi(tokens[4+9]);

        temp_record->Polygon.polygonV4->z[0]= atoi(tokens[5]);
        temp_record->Polygon.polygonV4->z[1]= atoi(tokens[5+3]);
        temp_record->Polygon.polygonV4->z[2]= atoi(tokens[5+6]);
        temp_record->Polygon.polygonV4->z[3]= atoi(tokens[5+9]);

        add(&head_ref, temp_record);
    }
}

void create(char **tokens)
{

    Record *recordFound = searchRecord(&head_ref, tokens[2]);
    if(recordFound == NULL)
    {
        printf("recordFound is found to be NULL\n");
        printf("Therefore, failed to find the record you passed in argument 2 of create command.\n");
        return;
    }
    else
    {
        printf("Record found.\n");
        printf("name: %s\n", recordFound->name);
        printf("x[0]=%d\n", recordFound->Polygon.polygonV3->x[0]);
    }

    Record *temp_record = (Record*)malloc(sizeof(Record));

    memcpy(temp_record, recordFound, sizeof(Record));

    temp_record->Polygon.polygonV3 = (PolygonV3*)malloc(sizeof(PolygonV3));
    temp_record->Polygon.polygonV4 = (PolygonV4*)malloc(sizeof(PolygonV4));

    /*
     * memcpy makes exact duplicates, bit by bit. I'm avoiding to allocate mem to Union Members of this structure due to the fact that
     * memcpy does it bit by bit, which'll yield the same result. And, we'll get the same name as specified in the recordFound's polygon fields,
     * Since we are creating a new object which will have different name than the polygon from which it gets its values,
     * so now we can replace the name value that we got through memcpy() 'name specified on token[1]'
     */
    temp_record->name = tokens[1];

    for(int i=3; tokens[i] != NULL; i++)
    {
        switch(tokens[i][0])
        {
        case 't':
            switch(tokens[i][1])
            {
            case 'X':
                if(temp_record->poly_type = V3)
                {
                    temp_record->Polygon.polygonV3->x[0] = recordFound->Polygon.polygonV3->x[0] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->x[1] = recordFound->Polygon.polygonV3->x[1] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->x[2] = recordFound->Polygon.polygonV3->x[2] + atoi(tokens[i+1]);
                }
                else
                {
                    temp_record->Polygon.polygonV3->x[0] = recordFound->Polygon.polygonV3->x[0] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->x[1] = recordFound->Polygon.polygonV3->x[1] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->x[2] = recordFound->Polygon.polygonV3->x[2] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->x[3] = recordFound->Polygon.polygonV3->x[3] + atoi(tokens[i+1]);
                }
                break;

            case 'Y':
                if(temp_record->poly_type = V3)
                {
                    temp_record->Polygon.polygonV3->y[0] = recordFound->Polygon.polygonV3->y[0] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->y[1] = recordFound->Polygon.polygonV3->y[1] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->y[2] = recordFound->Polygon.polygonV3->y[2] + atoi(tokens[i+1]);
                }
                else
                {
                    temp_record->Polygon.polygonV3->y[0] = recordFound->Polygon.polygonV3->y[0] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->y[1] = recordFound->Polygon.polygonV3->y[1] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->y[2] = recordFound->Polygon.polygonV3->y[2] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->y[3] = recordFound->Polygon.polygonV3->y[3] + atoi(tokens[i+1]);
                }
                break;

            case 'Z':
                if(temp_record->poly_type = V3)
                {
                    temp_record->Polygon.polygonV3->z[0] = recordFound->Polygon.polygonV3->z[0] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->z[1] = recordFound->Polygon.polygonV3->z[1] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->z[2] = recordFound->Polygon.polygonV3->z[2] + atoi(tokens[i+1]);
                }
                else
                {
                    temp_record->Polygon.polygonV3->z[0] = recordFound->Polygon.polygonV3->z[0] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->z[1] = recordFound->Polygon.polygonV3->z[1] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->z[2] = recordFound->Polygon.polygonV3->z[2] + atoi(tokens[i+1]);
                    temp_record->Polygon.polygonV3->z[3] = recordFound->Polygon.polygonV3->z[3] + atoi(tokens[i+1]);
                }
                break;
            }
            break;

        case 'r':
            // To be done
            break;

        case 's':
            // To be done
            break;

        default:
            // To be done
            break;
        }
    }

    /* All editing to temp_record is done at this point. So, now we can add it to the Record List */
    add(&head_ref, temp_record);
}

void transformation(char **tokens)
{

}

void assemble(char **tokens)
{

}

void extrude(char **tokens)
{

}


void (*command[5])(char **tokens)
{
    poly, create, transformation, assemble, extrude
};





void commandProcess(char *usersCommand)
{
    if(usersCommand == NULL)
    {
        printf("Command Passed is NULL.\n Hence returning.\n");
        return;
    }
    char *delim = " \t\n\f";
    char **tokens = (char**)malloc(1024);
    int i=0;

    /* Extracting tokens from command string. */
    for(tokens[i] = strtok(usersCommand, delim); tokens[i] != NULL; tokens[i] = strtok(NULL, delim))
    {
        i++;
    }

    /* Calling suitable function through jump table. */
    if(strcmp(tokens[0], "poly") == 0)
    {
        (*command[0])(tokens);
    }
    else if(strcmp(tokens[0], "create") == 0)
    {
        (*command[1])(tokens);
    }
    else if(strcmp(tokens[0], "transform") == 0)
    {
        (*command[2])(tokens);
    }
    else if(strcmp(tokens[0], "assemble") == 0)
    {
        (*command[3])(tokens);
    }
    else if(strcmp(tokens[0], "extrude") == 0)
    {
        (*command[3])(tokens);
    }

}



void fileProcess(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if(!file)
    {
        perror("file: ");
        exit(EXIT_FAILURE);
    }

    int BUFFER_LENGTH = 1024;
    char *buffer = (char*)malloc(BUFFER_LENGTH * sizeof(char*));
    char ch;
    int length = 0;

    while( (ch = fgetc(file)) )
    {
        /* This piece of code reads from file character by character and then saves it to char buffer[], which then is sent to commandProcess()
         * You can also use, getline() to get a line at a time. But it'll not be a portable thing to do, and is mostly you need to check if
         * it is available on your system or not
         */
        if( ch == EOF && length == 0)
        {
            /* This means the file is empty, so we cannot risk to send buffer to commandProcess(), otherwise some garbage value/ or something unknown
             * will be received on dereferencing this buffer. This might further lead to Unknown Behavior as well
             */
             printf("File is empty. \n By-passing the file reading routine... \n");
             break;
        }
        if(ch == EOF)
        {
            /* This is the end of the file, so now we know that the buffer[] now contains the last line and the next char on stream is EOF,
             * so now we can send this last line to the commandProcess() and break this loop
             */
            printf("%s sent to command-processor\n", buffer);
            commandProcess(buffer);
            break;
        }
        if(length > 1024)
        {
            BUFFER_LENGTH += 40;
            buffer = (char*)realloc(buffer, BUFFER_LENGTH);
            if(buffer == NULL)
            {
                printf("Error: Could not reallocate memory[%d bytes] to the buffer string.\n", BUFFER_LENGTH);
                exit(EXIT_FAILURE);
            }
        }

        buffer[length] = ch;
        length++;
        if(ch == '\n')
        {
            printf("%s sent to command-processor.\n", buffer);
            commandProcess(buffer);
            length = 0;
        }

    }

    fclose(file);
}
