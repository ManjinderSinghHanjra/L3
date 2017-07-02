#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include "Junction.h"

extern Record *record;

/* Command Processor */
void commandProcess(char command[]);

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



#endif // COMMANDPROCESSOR_H
