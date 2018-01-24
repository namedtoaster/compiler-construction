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
WS      [ \n]

%%

"+"|"-"|"="     { cout << "operator: " << yytext << endl; }
{DIGIT}+        { cout << "  number: " << yytext << endl; }
{LETTER}+       { cout << "      id: " << yytext << endl; }
{LPAREN}		{ cout << "  lparen: " << yytext << endl; }
{RPAREN}		{ cout << "  rparen: " << yytext << endl; }
{COMMA}			{ cout << "   comma: " << yytext << endl; }
{SEMIC}			{ cout << "   semic: " << yytext << endl; }
{WS}+           { }

%%

int main(int argc, char** argv)
{
    yyin = stdin;
    yylex();
    return 0;
}
