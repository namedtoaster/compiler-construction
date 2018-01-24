thermo : scanner.c parser.c parser.h thermo.cpp
	g++ scanner.c parser.c thermo.cpp -o thermo

scanner.c : thermo.l
	flex thermo.l

parser.c : thermo.y
	bison thermo.y

clean :
	rm -f scanner.c parser.c parser.h thermo
