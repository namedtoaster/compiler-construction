rpn : scanner.c parser.c parser.h rpn.cpp
	g++ scanner.c parser.c rpn.cpp -o rpn

scanner.c : rpn.l
	flex rpn.l

parser.c : rpn.y
	bison rpn.y

clean :
	rm -f scanner.c parser.c parser.h rpn
