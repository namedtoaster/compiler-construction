
%option noyywrap
%option outfile="scanner.c"

%{
#include <iostream>
#include <cstdlib>
#include "parser.h"
%}

%%

[0-9]+          { yylval = atoi(yytext); return NUM; }
[a-z]           { yylval = yytext[0] - 'a'; return VAR; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"="             { return ASSIGN; }
\n              { return EOL; }
[ \t]+          { }
.               { std::cout << "? : " << yytext << std::endl; }

%%
