all: clean
	g++ s21_list.cpp -std=c++17
	./a.out

clean:
	rm -rf a.out *.gch *.o test

run:
	./a.out

push:
	git add --all
	git commit -ms
	git push --all
testing:
	g++ list_test.cc
	./a.out