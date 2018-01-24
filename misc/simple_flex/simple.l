%option noyywrap

%{
    #include <iostream>
    using namespace std;
%}

LPAREN	[\(]
RPAREN	[\)]
COMMA	[,]
SEMIC	[;]
DIGIT   [0-9]
LETTER  [a-zA-Z]
OP 		(+|-|*|/|:=)
KWORD	(begin|end|read|write)
WS      [ \n]

%%

{LPAREN}		{ cout << "LPAREN" << endl; }
{RPAREN}		{ cout << "RPAREN" << endl; }
{COMMA}			{ cout << "COMMA" << endl; }
{SEMIC}			{ cout << "SEMIC" << endl; }
{OP}			{ cout << "OP: " << yytext << endl; }
{KWORD}			{ cout << "KWORD: " << yytext << endl;}
{WS}+           { }

%%

int main(int argc, char** argv)
{
    yyin = stdin;
    yylex();
    return 0;
}
