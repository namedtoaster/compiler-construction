%option noyywrap

%{
    #include <iostream>
    using namespace std;
%}

LPAREN	[\(]
RPAREN	[\)]
COMMA	[,]
SEMIC	[;]
DIG		[0-9]
LIT_INT [0(0-9)((1-9)(0-9)*)]
KWORD	("begin"|"end"|"read"|"write")
ALP		[a-zA-Z_]
WS      [ \n\t]

%%

"+"|"-"|"*"|"/"|":="     { cout << "OP: " << yytext << endl; }
(-?[1-9][0-9]*)|0		{ cout << "LIT_INT: " << yytext << endl; }
{KWORD}			{ cout << "KWORD: " << yytext << endl; }
({ALP})({ALP}|{DIG})*			{ cout << "ID: " << yytext << endl; }
{LPAREN}		{ cout << "LPAREN" << endl; }
{RPAREN}		{ cout << "RPAREN" << endl; }
{COMMA}			{ cout << "COMMA" << endl; }
{SEMIC}			{ cout << "SEMIC" << endl; }
{WS}+           { }
\"([^\"\\]|\\.)*\"		{ cout << "LIT_STR: " << yytext << endl; }

%%

int main(int argc, char** argv)
{
    yyin = stdin;
    yylex();
    return 0;
}
