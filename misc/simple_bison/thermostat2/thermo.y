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

heat_switch : TOKHEAT STATE
                { cout << "\tHeat was switched "
                       << (($2) ? "on" : "off") << endl; }
            ;

target_set  : TOKTARGET TOKTEMPERATURE NUMBER
                { cout << "\tTemperature set to " << $3 << endl; }
            ;

%%

void yyerror (char const * error)
{
    std::cerr << "ERROR: " << error << endl;
}
