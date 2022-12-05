vector_run:
	g++ s21_vector.cc -std=c++17
	./a.out

clean:
	rm -rf a.out

push:
	git add --all
	git commit -ms
	git push --all