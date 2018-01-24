/* Basic thermostat
 * derived from http://tldp.org/HOWTO/Lex-YACC-HOWTO-4.html */

%option noyywrap
%option outfile="scanner.c"

%{
#include <iostream>
#include "parser.h"
%}

%%

[0-9]+          { return NUMBER; }
heat            { return TOKHEAT; }
on|off          { return STATE; }
target          { return TOKTARGET; }
temperature     { return TOKTEMPERATURE; }
\n              { }
[ \t]+          { }
.               { std::cout << "? : " << yytext << std::endl; }

%%
