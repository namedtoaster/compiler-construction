%{
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void yyerror (char const * error);
int yylex();

int num = 0;
%}

%output = "parser.c"
%defines

%token NUM EOL RP LP
%left PLUS MINUS
%left TIMES DIV
%right EXP

%% 

input       :
            | input line
            ;

line        : EOL
            | expr EOL           { return 0; }
            ;

expr        : NUM               { $$ = num; cout << "n" << num++ << " [label = \"" << $1 << "\"]\n"; }
            | expr PLUS expr    { cout << "n" << num << " [label = \"+\"]\n";
            						cout << "n" << num << "->" << "n" << $1 << ";\n";
            						cout << "n" << num << "->" << "n" << $3 << ";\n"; $$ = num++; }
            | expr MINUS expr   { cout << "n" << num << " [label = \"-\"]\n";
            						cout << "n" << num << "->" << "n" << $1 << ";\n";
            						cout << "n" << num << "->" << "n" << $3 << ";\n"; $$ = num++; }
            | expr TIMES expr   { cout << "n" << num << " [label = \"*\"]\n";
            						cout << "n" << num << "->" << "n" << $1 << ";\n";
            						cout << "n" << num << "->" << "n" << $3 << ";\n"; $$ = num++;; }
            | expr DIV expr		{ cout << "n" << num << " [label = \"/\"]\n";
            						cout << "n" << num << "->" << "n" << $1 << ";\n";
            						cout << "n" << num << "->" << "n" << $3 << ";\n"; $$ = num++; }
            | expr EXP expr		{ cout << "n" << num << " [label = \"^\"]\n";
            						cout << "n" << num << "->" << "n" << $1 << ";\n";
            						cout << "n" << num << "->" << "n" << $3 << ";\n"; $$ = num++; }
            | LP expr RP		{ $$ = $2; }
            ;

%%

void yyerror (char const * error)
{
    std::cerr << "ERROR: " << error << endl;
}