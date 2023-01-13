CC 				= 	g++
CFLAGS 			= 	-Wall -Wextra -Werror -std=c++17
CHECKFLAGS 		= 	-lgtest -lgtest_main -pthread

LIBNAME			=	s21_array.h

SRCFOLDER 		=	source/
OBJFOLDER		=	objects/

SRCTESTSFOLDER	=	tests/

GCOVFOLDER		=	gcov/
TESTEXEC		=	$(GCOVFOLDER)run_tests

REPORTFOLDER	=	report/
REPORTFILE		=	$(REPORTFOLDER)gcov_report.info

SRCSTESTS		= 	$(wildcard $(SRCTESTSFOLDER)*.cc)
OBJSTESTS		=	$(patsubst $(SRCTESTSFOLDER)%, $(OBJFOLDER)%, $(SRCSTESTS:%.cc=%.o))

ALLPROJECT		=	$(SRCS) $(SRCSTESTS) $(LIBNAME:.a=.h)

$(OBJFOLDER)%.o: $(SRCTESTSFOLDER)%.cc
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -o $@ -c $<

all: test

test: $(OBJSTESTS)
	@mkdir -p $(GCOVFOLDER)
	$(CC) $(CFLAGS) $(OBJSTESTS) --coverage s21_array.h -o $(TESTEXEC) $(CHECKFLAGS)
	./$(TESTEXEC)

clean:
	rm -rf s $(OBJFOLDER) $(REPORTFOLDER) $(GCOVFOLDER) .clang-format

check:
	cppcheck --enable=all --force --check-config for details $(ALLPROJECT)
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(ALLPROJECT)

push:
	@read -p "Enter commit name no spaces: " comm; \
	git add --all; \
	git commit -m$$comm; \
	git push origin assassin

.PHONY: all, test, clean, check, push