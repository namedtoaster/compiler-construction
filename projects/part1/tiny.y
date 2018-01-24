/* This is the parser specification for the TINY language */

%{
#include <iostream>
#include "AST.h"

int yylex();
void yyerror(struct AST **, char const * p);

%}

%output = "gen/parser.c"
%defines

%parse-param { struct AST ** rootpointer }

%union {
    struct AST * node;
    struct Id * ident;
    char * str;
    int num;
};

%token <num> NUMBER
%token <str> ID

%right ASN
%nonassoc LP
%token RP LC RC
%left LT GT EQ
%left PLUS MINUS
%left TIMES DIVIDE
%token VAR SEMI IF ELSE WHILE READ WRITE PASS

%type <node> exp program stmt stmtlist block
%type <ident> id

%%
program : stmtlist                      { $$ = $1; *rootpointer = $1; }

stmtlist: stmt stmtlist                 { $$ = new SList($1, $2); }
        | stmt                          { $$ = $1; }

stmt    : VAR id ASN exp SEMI           { $$ = new Declaration($2, $4); }
        | id ASN exp SEMI               { $$ = new Assign($1, $3); }
        | READ id SEMI                  { $$ = new Read($2); }
        | WRITE id SEMI                 { $$ = new Write($2); }
        | IF LP exp RP block ELSE block { $$ = new If($3, $5, $7); }
        | WHILE LP exp RP block         { $$ = new While($3, $5); }
        | block                         { $$ = $1; }
        | PASS SEMI                     { $$ = new Pass(); }
 
block   : LC stmtlist RC                { $$ = new Block($2); }

exp     : NUMBER                        { $$ = new Number($1); }
        | id                            { $$ = $1; }
        | exp PLUS exp                  { $$ = new Plus($1, $3); }
        | exp MINUS exp                 { $$ = new Minus($1, $3); }
        | exp TIMES exp                 { $$ = new Times($1, $3); }
        | exp DIVIDE exp                { $$ = new Divide($1, $3); }
        | exp LT exp                    { $$ = new LessThan($1, $3); }
        | exp GT exp                    { $$ = new GreaterThan($1, $3); }
        | exp EQ exp                    { $$ = new EqualTo($1, $3); }

id      : ID                            { $$ = new Id($1); }
%%


void yyerror(struct AST **, char const * p)
{
    std::cerr << "Parser: " << p << std::endl;
}
