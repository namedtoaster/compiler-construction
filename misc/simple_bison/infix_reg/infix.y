%{
#include <iostream>
using namespace std;

void yyerror (char const * error);
int yylex();

int vars[26];

%}

%output = "parser.c"
%defines

%token NUM EOL VAR
%right ASSIGN
%left PLUS MINUS
%left TIMES

%% 

input       :
            | input line
            ;

line        : EOL
            | exp EOL           { cout << $1 << endl; }
            ;

exp         : NUM               { $$ = $1; }
            | VAR               { $$ = vars[$1]; }
            | exp PLUS exp      { $$ = $1 + $3; }
            | exp MINUS exp     { $$ = $1 - $3; }
            | exp TIMES exp     { $$ = $1 * $3; }
            | VAR ASSIGN exp    { vars[$1] = $3; $$ = $3; }
            ;

%%

void yyerror (char const * error)
{
    std::cerr << "ERROR: " << error << endl;
}
