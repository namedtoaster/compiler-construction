infix : scanner.c parser.c parser.h file.cpp
	g++ scanner.c parser.c file.cpp -o infix2tree

scanner.c : file.l
	flex file.l

parser.c : file.y
	bison file.y

clean :
	rm -f scanner.c parser.c parser.h a4
