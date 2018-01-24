%{
#include <iostream>
using namespace std;

void yyerror (char const * error);
int yylex();
%}

%output = "parser.c"
%defines

%token NUM PLUS MINUS EOL

%% 

input       :
            | input line
            ;

line        : EOL
            | exp EOL           { cout << $1 << endl; }
            ;

exp         : NUM               { $$ = $1; }
            | exp exp PLUS      { $$ = $1 + $2 }
            | exp exp MINUS     { $$ = $1 - $2 }
            ;

%%

void yyerror (char const * error)
{
    std::cerr << "ERROR: " << error << endl;
}
