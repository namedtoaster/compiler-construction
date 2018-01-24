all: scanner

lex.yy.c : simple.l
	flex simple.l

scanner : lex.yy.c
	g++ lex.yy.c -o scanner

test : scanner expr.txt
	./scanner < expr.txt

clean :
	rm -f lex.yy.c scanner

