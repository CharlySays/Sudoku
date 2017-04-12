#ifndef grid_h
#define grid_h

#include <grid.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <util.h>
#include <math.h>


typedef struct{
    int value;
    char show[10];
    bool correct;
    bool fixed;
}Field;

void render(Field grid[][9] ,int X, int Y);
void renderInt(Field grid[][9] ,int X, int Y);

bool readGrid(Field grid[][9]);
bool readGridWithFile(Field grid[][9], FILE *myFile);
char* itoa(int value, char* result, int base);
bool insertValue(Field grid[][9], int value, int X, int Y);
bool isfixed(Field grid[][9], int X, int Y);

#endif
