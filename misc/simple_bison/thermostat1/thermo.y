%{
#include <iostream>
using namespace std;

void yyerror (char const * error);
int yylex();
%}

%output = "parser.c"
%defines

%token NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE

%% 

command_list:
            | command_list command
            ;

command     : heat_switch
            | target_set
            ;

heat_switch : TOKHEAT STATE     { cout << "Heat was switched" << endl; }
            ;

target_set  : TOKTARGET TOKTEMPERATURE NUMBER
                { cout << "Temperature set" << endl; }
            ;

%%

void yyerror (char const * error)
{
    std::cerr << "ERROR: " << error << endl;
}
