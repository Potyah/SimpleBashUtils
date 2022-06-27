.PHONY: all clean test s21_grep check
CC=gcc
FILES= s21_grep.c\

LDFLAGS= -Wall -Wextra -Werror -std=c11 -g
OS := $(shell uname -s)
LCHECK= `pkg-config --libs check`

ifeq ($(OS), Darwin)
	CC += -D OS_MAC
else
	CC += -D OS_LINUX
endif

default: all

all: clean s21_grep test

test:
ifeq ($(OS), Darwin)
	$(CC) ../common/s21_grep_tests.c -o test $(LCHECK)
else
	$(CC) ../common/s21_grep_tests.c -o test $(LCHECK)
endif
	./test

clean:
	rm -rf test s21_grep *.cfg

s21_grep:
	$(CC) $(FILES) -D_GNU_SOURCE -lm -o s21_grep

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./s21_grep
else
	valgrind --leak-check=full --show-leak-kinds=all ./s21_grep
endif
