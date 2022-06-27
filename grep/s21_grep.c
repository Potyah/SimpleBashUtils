#include "s21_grep.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        struct flags flag;
        setEmptyGrepStruct(&flag);
        s21_grep(&flag, argc, argv);
    }

    return 0;
}

void s21_grep(struct flags* flag, int argc, char** argv) {
    char search[8192] = "";
    int count = 0;
    int exitFlag = 0;

    while (1) {
        char opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL);

        if (opt == -1) {
            break;
        }

        switch (opt) {
            case 'e':
                flag -> isE = 1;
                strcat(search, optarg);
                strcat(search, " ");
                optarg = NULL;
                break;
            case 'i':
                flag -> isI = 1;
                break;
            case 'v':
                flag -> isV = 1;
                break;
            case 'c':
                flag -> isC = 1;
                break;
            case 'l':
                flag -> isL = 1;
                break;
            case 'n':
                flag -> isN = 1;
                break;
            case 'h':
                flag -> isH = 1;
                break;
            case 's':
                flag -> isS = 1;
                break;
            case 'f':
                flag -> isF = 1;
                readFile(optarg, search);
                optarg = NULL;
                count = optind;
                break;
            case 'o':
                flag -> isO = 1;
                break;
        }
    }

    if (flag -> isV == 1 && flag -> isO == 1) {
        exitFlag = 1;
    }

    if ((flag -> isO == 1 && flag -> isC == 1) || (flag -> isO == 1 && flag -> isL == 1)) {
        flag -> isO = 0;
    }

    if (flag -> isE == 0 && flag -> isF == 0) {
        strcat(search, argv[optind]);
        count = optind + 1;
    } else {
        count = optind;
    }

    if (exitFlag != 1) {
        printGrep(flag, argv, count, search);
    }
}

void printGrep(struct flags* flag, char** argv, int count, char* search) {
    int isNextFile = 1;

    if (argv[count + 1] != NULL) {
        isNextFile = 0;
    }

    if (flag -> isH == 1) {
        isNextFile = 1;
    }

    int regFlag = getRegexFlag(flag);
    int compare = getCompare(flag);
    int flagV = 0;
    int lineCount = 1;
    int coincidenceCount = 0;
    int flagL = 0;
    char line[8192];
    int lastSymbolFlag = 0;
    char* DELIM = " ";

    if (flag -> isF == 1) {
      DELIM = "***";
    }

    while (argv[count] != NULL) {
        FILE* file;
        file = fopen(argv[count], "r");

        if (file == NULL) {
            if (flag -> isS == 0) {
                fprintf(stderr, "grep: %s: No such file or catalog\n", argv[count]);
            }

            count++;
        } else {
            char* token = NULL;
            char copySearch[8192];

            sprintf(copySearch, "%s", search);

            if (flag -> isO == 1) {
                printO(argv[count], isNextFile, search, file, compare, regFlag, DELIM);
            } else {
                while (fgets(line, 8192, file) != NULL) {
                    token = strtok(copySearch, DELIM);

                    while (token != NULL) {
                        regex_t preg;
                        regcomp(&preg, token, regFlag);
                        int regexReturn = regexec(&preg, line, (size_t) 0, NULL, 0);
                        int breakFlag = 0;

                        if (regexReturn == compare) {
                            if (flag -> isE == 1 && flag -> isV == 1) {
                                flagV = 1;
                            } else {
                                printFile(flag, isNextFile, &coincidenceCount,
                                        lineCount, argv[count], line, &flagL, &lastSymbolFlag);
                                breakFlag = 1;
                            }
                        } else if (flag -> isE == 1 && flag -> isV == 1) {
                            flagV = 0;
                            breakFlag = 1;
                        }

                        if (breakFlag == 1) {
                            regfree(&preg);
                            break;
                        }

                        regfree(&preg);
                        token = strtok(NULL, DELIM);
                    }

                    if (flagV == 1) {
                        printFile(flag, isNextFile, &coincidenceCount,
                            lineCount, argv[count], line, &flagL, &lastSymbolFlag);
                    }

                    token = NULL;
                    lineCount++;
                    memset(line, 0, 8192);
                    sprintf(copySearch, "%s", search);
                }
            }

            if (lastSymbolFlag == 1 && line[strlen(line) - 1] != '\n')
                printf("\n");

            fclose(file);
            printNameAndCount(flag, argv[count], flagL, isNextFile, coincidenceCount);
            coincidenceCount = 0;
            lineCount = 1;
            flagL = 0;
            count++;
        }
    }
}

void printFile(struct flags* flag, int isNextFile, int* coincidenceCount,
                int lineCount, char* fileName, char* line, int* flagL, int* lastSymbolFlag) {
    *coincidenceCount += 1;

    if (flag -> isL == 1) {
        *flagL = 1;
    } else if (flag -> isC == 0) {
        if (isNextFile == 0) {
            printf("%s:", fileName);
        }

        if (flag -> isN == 1) {
            printf("%d:", lineCount);
        }

        printf("%s", line);

        if (line[strlen(line) - 1] != '\n') {
            *lastSymbolFlag = 1;
        }
    }
}

void printO(char* fileName, int isNextFile, char* search, FILE* file, int compare, int regFlag, char* delim) {
    char* token;
    char line[8192];
    int minEO;
    int minSO;
    regmatch_t pm;
    char copySearch[8192];
    sprintf(copySearch, "%s", search);

    while (fgets(line, 8192, file) != NULL) {
        char* temp = line;
        int i = 0;

        while (1) {
            regex_t preg;
            int firstFoundFlag = 0;
            minEO = 0;
            minSO = 0;
            token = strtok(copySearch, delim);
            regcomp(&preg, token, regFlag);
            int regerror = regexec(&preg, temp, 1, &pm, 0);

            if (regerror == compare) {
                minEO = pm.rm_eo;
                minSO = pm.rm_so;
                firstFoundFlag = 1;
            }

            token = strtok(NULL, delim);
            regfree(&preg);

            while (token != NULL) {
                regex_t newPreg;
                regcomp(&newPreg, token, regFlag);
                regerror = regexec(&newPreg, temp, 1, &pm, 0);

                if (regerror == compare) {
                    if (pm.rm_so < minSO || firstFoundFlag == 0) {
                        minEO = pm.rm_eo;
                        minSO = pm.rm_so;
                    }
                }

                regfree(&newPreg);
                token = strtok(NULL, delim);
            }

            if (minEO != 0 || minSO != 0) {
                if (isNextFile == 0) {
                    printf("%s:", fileName);
                }

                for (i = minSO; i < minEO; ++i) {
                    printf("%c", temp[i]);
                }

                temp = temp + minEO;
                printf("\n");
                sprintf(copySearch, "%s", search);
            } else {
                sprintf(copySearch, "%s", search);

                break;
            }
        }
    }
}

void printNameAndCount(struct flags* flag, char* fileName,
                        int flagL, int isNextFile, int coincidenceCount) {
    if (flagL == 1) {
        printf("%s\n", fileName);
    } else if (flag -> isC == 1) {
        if (isNextFile == 0) {
            printf("%s:", fileName);
        }

        printf("%d\n", coincidenceCount);
    }
}

int getRegexFlag(struct flags* flag) {
    int regFlag = 0;

    if (flag -> isI == 1) {
        regFlag = REG_ICASE;
    }

    return regFlag;
}

int getCompare(struct flags* flag) {
    int compare = 0;

    if (flag -> isV == 1) {
        compare = REG_NOMATCH;
    }

    return compare;
}

void readFile(char* fileName, char* regular) {
    FILE* file = fopen(fileName, "rb");

    if (file == NULL) {
        fprintf(stderr, "grep: %s: No such file or catalog\n", fileName);
    } else {
        char line[8192];

        while (fgets(line, 8192, file) != NULL) {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }

            strcat(regular, line);
            strcat(regular, "***");
        }

        fclose(file);
    }
}

void setEmptyGrepStruct(struct flags* flag) {
    flag -> isE = 0;
    flag -> isI = 0;
    flag -> isV = 0;
    flag -> isC = 0;
    flag -> isL = 0;
    flag -> isN = 0;
    flag -> isH = 0;
    flag -> isS = 0;
    flag -> isF = 0;
    flag -> isO = 0;
}
