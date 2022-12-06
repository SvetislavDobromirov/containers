CFLAGS 			=	-std=c++17 # -Wall -Wextra -Werror
CHECKFLAGS 		= 	-lgtest -lgtest_main -pthread


vector_run: clean
	g++ -c s21_vector.cc main.cc -std=c++17
	g++ *.o
	./a.out

clean:
	rm -rf a.out *.gcno *.o *.gcda

push:
	git add --all
	git commit -ms
	git push --all

test: clean
	g++ $(CFLAGS) -c tests/test_run.cc
#g++ $(CFLAGS) -c  s21_vector.cc
	g++ $(CFLAGS) *.o --coverage *.cc -o test $(CHECKFLAGS)
#./test
