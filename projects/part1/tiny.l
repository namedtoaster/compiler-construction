/* This is the scanner specificication for the TINY language */

%option noyywrap
%option outfile="gen/scanner.c"

%{
#include <iostream>
#include <cstdlib>
#include "gen/parser.h"
%}

%%

[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LP; }
")"             { return RP; }
"{"             { return LC; }
"}"             { return RC; }
":="            { return ASN; }
";"             { return SEMI; }
"<"             { return LT; }
">"             { return GT; }
"="             { return EQ; }
var             { return VAR; }
if              { return IF; }
else            { return ELSE; }
while           { return WHILE; }
read            { return READ; }
write           { return WRITE; }
pass            { return PASS; }
[a-zA-Z_]+      { yylval.str = yytext; return ID; }
[ \t\n]+        { /* ignore whitespace */ }
"#".*           { /* ignore anything after a # to the end of the line */ }
.               { std::cerr << "Scanner: " << yytext << std::endl; }

%%
