CFLAGS 			=	-std=c++17 # -Wall -Wextra -Werror
CHECKFLAGS 		= 	-lgtest -lgtest_main -pthread

REPORTFOLDER	=	report/
REPORTFILE		=	$(REPORTFOLDER)gcov_report.info


vector_run: clean
	g++  -c s21_vector.h  -std=c++17

clean:
	rm -rf a.out *.gcno *.o *.gcda report *.gch s21 test

push:
	git add --all
	git commit -ms
	git push --all

test: clean
	g++ $(CFLAGS) -c --coverage tests/test_run.cc
#g++ $(CFLAGS) -c  s21_vector.cc
	g++ $(CFLAGS) *.o --coverage -o test $(CHECKFLAGS)
	./test

s21_vector.a:
	ar rc s21_vector.a *.cc
	ranlib s21_vector.a


gcov_report: test
	mkdir -p gcov/
	mkdir report/
	lcov -t "s21_vector.a" -o $(REPORTFILE) -c -d .
	genhtml $(REPORTFILE) -o $(REPORTFOLDER)
	open $(REPORTFOLDER)index.html

