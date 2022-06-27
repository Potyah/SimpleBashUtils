#include "s21_cat.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        struct flags flag;
        setEmptyCatStruct(&flag);
        s21_cat(&flag, argc, argv);
    }

    return 0;
}

void s21_cat(struct flags* flag, int argc, char** argv) {
    int count = 0;

    while (1) {
        static struct option longOptions[] = {
            {"number-nonblank", 0, 0, 'b'},
            {"number", 0, 0, 'n'},
            {"squeeze-blank",  0, 0, 's'},
            {NULL, 0, NULL, 0}
            };

        char opt = getopt_long(argc, argv, "beEnstTv", longOptions, NULL);

        if (opt == -1) {
            break;
        }

        switch (opt) {
            case 'b':
                flag -> isB = 1;
                break;
            case 'e':
                flag -> isE = 1;
                flag -> isV = 1;
                break;
            case 'E':
                flag -> isE = 1;
                break;
            case 'n':
                flag -> isN = 1;
                break;
            case 's':
                flag -> isS = 1;
                break;
            case 't':
                flag -> isT = 1;
                flag -> isV = 1;
                break;
            case 'T':
                flag -> isT = 1;
                break;
            case 'v':
                flag -> isV = 1;
                break;
        }
    }

    count = optind;

    if (flag -> isB == 1 && flag -> isN == 1) {
        flag -> isN = 0;
    }

    while (argv[count] != NULL) {
        s21_printFile(flag, argv[count]);
        count++;
    }
}

void s21_printFile(struct flags* flag, char* argv) {
    FILE* file = fopen(argv, "r");
    int numberCount = 0;

    if (file == NULL) {
        fprintf(stderr, "cat: %s: No such file or catalog\n", argv);
    } else {
        char currentChar = fgetc(file);
        char nextChar;
        int firstSpaceFlag = 0;

        if (currentChar != '\xff') {
            if (flag -> isN == 1 || (flag -> isB == 1 && currentChar != '\n')) {
                printf("%6d%c", numberCount += 1, '\t');
            }

            printDollar(flag, currentChar);

            while ((nextChar = getc(file)) != '\xff') {
                firstSpaceCheck(file, flag, &currentChar, &nextChar, &firstSpaceFlag);
                skipSqueeze(&file, flag, currentChar, &nextChar, &numberCount);

                if (nextChar != '\xff') {
                    printCountN(file, flag, &currentChar, &nextChar, &numberCount);

                    if (nextChar != '\xff') {
                        printChar(flag, currentChar);
                        printCountB(flag, currentChar, nextChar, &numberCount);
                        printDollar(flag, nextChar);

                        currentChar = nextChar;
                    }
                }
            }

            if (currentChar != '\xff') {
                printChar(flag, currentChar);
            }
        }

        fclose(file);
    }
}

void firstSpaceCheck(FILE* file, struct flags* flag, char* currentChar, char* nextChar, int* firstSpaceFlag) {
    while (*currentChar == '\n' && *firstSpaceFlag == 0 && *nextChar == '\n' && flag -> isS == 1) {
            *currentChar = *nextChar;
            *nextChar = fgetc(file);
        }

        *firstSpaceFlag = 1;
}

void skipSqueeze(FILE** file, struct flags* flag, char currentChar, char* nextChar, int* numberCount) {
    if (flag -> isS == 1) {
        if (currentChar == '\n' && *nextChar == '\n') {
            while (*nextChar == '\n' && *nextChar != EOF) {
                *nextChar = fgetc(*file);
            }

            printf("%c", '\n');

            if (flag -> isN == 1 && currentChar == '\n') {
                printf("%6d%c", *numberCount += 1, '\t');
            }

            printDollar(flag, currentChar);
        }
    }
}

void printChar(struct flags* flag, char currentChar) {
    int invisibleFlag = 0;

    if (flag -> isV == 1) {
        invisibleFlag = printInvisibleSymbol(flag, currentChar);
    }

    if (invisibleFlag == 0) {
        printf("%c", currentChar);
    }
}

int printInvisibleSymbol(struct flags* flag, char currentChar) {
    int invisibleFlag = 0;

    if (currentChar < 0) {
        printf("M-");
        currentChar -= 128;
    }

    if (currentChar >= 0 && currentChar < 32 && currentChar != 10) {
        currentChar += 64;
        printf("%s%c", "^", currentChar);
        invisibleFlag = 1;
    }

    if (currentChar == 127) {
        printf("^?");
        invisibleFlag = 1;
    }

    return invisibleFlag;
}

void printDollar(struct flags* flag, char nextChar) {
    if (nextChar == '\n' && flag -> isE == 1) {
        printf("%c", '$');
        }
}

void printCountN(FILE* file, struct flags* flag, char* currentChar, char* nextChar, int* numberCount) {
    while (*currentChar == '\n' && flag -> isN == 1 && flag -> isS == 0 && *nextChar != EOF) {
        char pastChar = *nextChar;

        printChar(flag, *currentChar);

        *currentChar = *nextChar;
        *nextChar = getc(file);

        printf("%6d%c", *numberCount += 1, '\t');
        printDollar(flag, pastChar);
    }
}

void printCountB(struct flags* flag, char currentChar, char nextChar, int* numberCount) {
    if (currentChar == '\n' && nextChar != '\n' && (flag -> isB == 1 || flag -> isN == 1)) {
        printf("%6d%c", *numberCount += 1, '\t');
    }
}

void setEmptyCatStruct(struct flags* flag) {
    flag -> isB = 0;
    flag -> isE = 0;
    flag -> isN = 0;
    flag -> isS = 0;
    flag -> isT = 0;
    flag -> isV = 0;
}
