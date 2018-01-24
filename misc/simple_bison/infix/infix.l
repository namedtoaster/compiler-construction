
%option noyywrap
%option outfile="scanner.c"

%{
#include <iostream>
#include <cstdlib>
#include "parser.h"
%}

%%

[0-9]+          { yylval = atoi(yytext); return NUM; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"				{ return DIV; }
"^"				{ return EXP; }
")"				{ return RP; }
"("				{ return LP; }
\n              { return EOL; }
[ \t]+          { }
.               { std::cout << "? : " << yytext << std::endl; }

%%