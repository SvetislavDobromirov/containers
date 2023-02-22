CFLAGS 			=	-std=c++17  -Wall -Wextra -Werror
CHECKFLAGS 		= 	-lgtest -lgtest_main -pthread

REPORTFOLDER	=	report/
REPORTFILE		=	$(REPORTFOLDER)gcov_report.info


vector_run:
	g++  -c s21_vector.h  -std=c++17

clean:
	rm -rf a.out *.gcno *.o *.gcda report *.gch s21 test .vs* .DS* *tar


push:
	git add --all
	git commit -ms
	git push --all

#TODO: remove clean
test: clean
	g++ $(CFLAGS) -c tests/run_test.cc
	#g++ $(CFLAGS) -c tests/test_list.cc
	# g++ $(CFLAGS) -c tests/test_map.cc
	# g++ $(CFLAGS) -c tests/test_queue.cc
	# g++ $(CFLAGS) -c tests/test_set.cc
	# g++ $(CFLAGS) -c tests/test_stack.cc
	# g++ $(CFLAGS) -c tests/test_vector.cc
	# g++ $(CFLAGS) -c -g tests/test_multiset.cc
	g++ $(CFLAGS) -c -g tests/test_array.cc

	g++ $(CFLAGS) *.o -o test $(CHECKFLAGS)
	make run

test_memory:
	g++ $(CFLAGS) -c -g tests/run_test.cc
	# g++ $(CFLAGS) -c -g tests/test_list.cc
	# g++ $(CFLAGS) -c -g tests/test_map.cc
	# g++ $(CFLAGS) -c -g tests/test_queue.cc
	# g++ $(CFLAGS) -c -g tests/test_set.cc
	# g++ $(CFLAGS) -c -g tests/test_stack.cc
	# g++ $(CFLAGS) -c -g tests/test_vector.cc
	# g++ $(CFLAGS) -c -g tests/test_multiset.cc
	g++ $(CFLAGS) -c -g tests/test_array.cc
	g++ $(CFLAGS) *.o -g -o test $(CHECKFLAGS)
	valgrind --leak-check=full ./test


run:
	./test

testing:
	g++ $(CFLAGS) -c -g --coverage list/s21*.cpp
	
	#g++ $(CFLAGS) -c -g --coverage list/test.cc
	g++ $(CFLAGS) *.o -g --coverage -o test $(CHECKFLAGS)
	./test




gcov_report: clean
	g++ $(CFLAGS) -c -g --coverage tests/run_test.cc
		g++ $(CFLAGS) -c -g --coverage tests/test_array.cc

#g++ $(CFLAGS) -c -g --coverage tests/test_multiset.cc
#g++ $(CFLAGS) -c -g --coverage tests/test_*.cc
	g++ $(CFLAGS) *.o -g --coverage -o test $(CHECKFLAGS)
	mkdir -p gcov/
	mkdir report/
	./test
	lcov -t "s21_vector.a" -o $(REPORTFILE) -c -d .
	genhtml $(REPORTFILE) -o $(REPORTFOLDER)
	xdg-open $(REPORTFOLDER)index.html

