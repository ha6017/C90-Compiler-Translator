CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/maths_parser.tab.cpp src/maths_parser.tab.hpp : src/maths_parser.y
	bison -v -d src/maths_parser.y -o src/maths_parser.tab.cpp

src/maths_lexer.yy.cpp : src/maths_lexer.flex src/maths_parser.tab.hpp
	flex -o src/maths_lexer.yy.cpp  src/maths_lexer.flex

bin/c_compiler : src/c_compiler.o src/maths_parser.tab.o src/maths_lexer.yy.o src/maths_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^


.PHONY: clean

clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.tab.hpp
	rm -f *.output
	rm -f src/*.yy.cpp
