
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
\n              { return EOL; }
[ \t]+          { }
.               { std::cout << "? : " << yytext << std::endl; }

%%
