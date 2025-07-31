CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17 -lm

OS= $(shell uname)
ifeq ("$(OS)","Linux")
	TEST_FLAGS = -lgtest -lpthread
else
	TEST_FLAGS = -lgtest
endif


all: s21_matrix_oop.a test

s21_matrix_oop.a: 
	${CC} ${FLAGS} -c *.cpp 
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
	${CC} ${FLAGS} tests/*.cpp -o test.out ${TEST_FLAGS} -L. -l:s21_matrix_oop.a
	./test.out

gcov_report: 
	${CC} ${FLAGS} -fprofile-arcs -ftest-coverage *.cpp tests/*.cpp -o test.out ${TEST_FLAGS}
	./test.out
	lcov -t "test.result" -o test.info -c -d .
	genhtml -o report test.info

clean:
	rm -f *.o *.obj *.out *.gcda *.gcno *.info
	rm -rf report

style:
	clang-format -i *.cpp tests/*.cpp

style_check:
	clang-format -n *.cpp tests/*.cpp
