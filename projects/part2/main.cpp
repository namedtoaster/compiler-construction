#include <iostream>

#include "AST.h"
#include "GVEmitter.h"
#include "ILOCEmitter.h"

int yyparse(AST ** rootpointer);

int main(int argc, char const * argv[])
{
    AST * root;
    int error = yyparse(&root);

    if (error) return error;

    // GVEmitter gve;
    // std::cout << "digraph {" << std::endl;
    // root->accept(&gve);
    // std::cout << "}" << std::endl;

    ILOCEmitter ie;
    root->accept(&ie);

    return 0;
}
