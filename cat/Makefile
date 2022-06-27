.PHONY: all clean test s21_cat check
CC=gcc
FILES= s21_cat.c\

LDFLAGS= -Wall -Wextra -Werror -std=c11 -g
OS := $(shell uname -s)
LCHECK= `pkg-config --libs check`

ifeq ($(OS), Darwin)
	CC += -D OS_MAC
else
	CC += -D OS_LINUX
endif

default: all

all: clean s21_cat test

test: 
ifeq ($(OS), Darwin)
	$(CC) ../common/s21_cat_tests.c -o test $(LCHECK)
else
	$(CC) ../common/s21_cat_tests.c -o test $(LCHECK)
endif
	./test

clean:
	rm -rf test s21_cat *.cfg

s21_cat:
	$(CC) $(FILES) -D_GNU_SOURCE -lm -o s21_cat

check: 
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./s21_cat
else
	valgrind --leak-check=full --show-leak-kinds=all chmod a+x ./s21_cat
endif
