#ifndef S21_GREP_H
#define S21_GREP_H
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <regex.h>

struct flags {
    int isE;
    int isI;
    int isV;
    int isC;
    int isL;
    int isN;
    int isH;
    int isS;
    int isF;
    int isO;
};

void s21_grep(struct flags* flag, int argc, char** argv);
void printGrep(struct flags* flag, char** argv, int count, char* search);
void printFile(struct flags* flag, int isNextFile, int* coincidenceCount, int lineCount, char* fileName, char* line, int* flagL, int* lastSymbolFlag);
void printNameAndCount(struct flags* flag, char* fileName, int flagL, int isNextFile, int coincidenceCount);

void printO(char* fileName, int isNextFile, char* search, FILE* file, int compare, int regFlag, char* delim);

int isNextFileCheck(struct flags* flag, const char** argv, int count);
void setEmptyGrepStruct(struct flags* flag);

int getRegexFlag(struct flags* flag);
int getCompare(struct flags* flag);
void readFile(char* fileName, char* regular);

#endif