/*
 *  List of Commands that are available
 *
 *  "poly"
 *  "create"
 *  "copy"
 *  "extrude"
 *  "assemble"
 *  "translatex/ translateY/ translateZ/ tX/ tY/ tZ"
 *  "rotateX/ rotateY/ rotateZ/ rX/ rY/ rZ"
 *
 *  Symmetric 3D objects Qualify these commands too
 *  Stuff to be done yet
 */



#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include "Junction.h"

extern Record *record;

/* Command Processor */
void commandProcess(char usersCommand[]);

void fileProcess(const char *filename);


extern char *set_of_commands[];

void poly(char **args);

void create(char **args);

void transformation(char **args);

void assemble(char **args);

void extrude(char **args);

extern void (*command[])(char **args);

#endif // COMMANDPROCESSOR_H
