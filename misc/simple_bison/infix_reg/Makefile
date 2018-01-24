infix : scanner.c parser.c parser.h infix.cpp
	g++ scanner.c parser.c infix.cpp -o infix

scanner.c : infix.l
	flex infix.l

parser.c : infix.y
	bison infix.y

clean :
	rm -f scanner.c parser.c parser.h infix
