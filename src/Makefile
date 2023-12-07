CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a test

clean:
		rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
		rm -rf report/

test: s21_math.a
		${CC} ${FLAGS} main.c tests/test_*.c s21_math.a -g `pkg-config --cflags --libs check` -lm

s21_math.a: s21_math.o
		ar rc s21_math.a s21_math.o
		ranlib s21_math.a

gcov_report:
		${CC} -fprofile-arcs -ftest-coverage ${FLAGS} s21_math.c tests/test_*.c main.c -g `pkg-config --cflags --libs check` -lm
		./a.out
		lcov -t "coverage_report" -o coverage.info -c -d .
		genhtml -o report coverage.info


s21_math.o: s21_math.c
		${CC} ${FLAGS} -O -c s21_math.c

tst:
		${CC} ${FLAGS} s21_math.c tests/test_*.c main.c -g `pkg-config --cflags --libs check` -lm		
