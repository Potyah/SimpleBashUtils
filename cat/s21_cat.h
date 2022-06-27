#ifndef S21_CAT_H
#define S21_CAT_H
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

struct flags {
    int isB;
    int isE;
    int isN;
    int isS;
    int isT;
    int isV;
};

void setEmptyCatStruct(struct flags* flag);

void s21_cat(struct flags* flag, int argc, char** argv);
void s21_printFile(struct flags* flag, char* argv);

void firstSpaceCheck(FILE* file, struct flags* flag, char* currentChar, char* nextChar, int* firstSpaceFlag);
void skipSqueeze(FILE** file, struct flags* flag, char currentChar, char* nextChar, int* numberCount);
void printChar(struct flags* flag, char currentChar);
void printCountB(struct flags* flag, char currentChar, char nextChar, int* numberCount);
void printCountN (FILE* file, struct flags* flag, char* currentChar, char* nextChar, int* numberCount);
int printInvisibleSymbol(struct flags* flag, char currentChar);
void printDollar(struct flags* flag, char nextChar);

#endif
