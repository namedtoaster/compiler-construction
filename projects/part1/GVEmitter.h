#ifndef GVEMITTER_H
#define GVEMITTER_H

#include "AST.h"

struct GVEmitter : public ASTVisitor
{
    GVEmitter();
    virtual void visit(Number *);
    virtual void visit(Plus *);
    virtual void visit(Minus *);
    virtual void visit(Times *);
    virtual void visit(Divide *);
    virtual void visit(Id *);
    virtual void visit(LessThan *);
    virtual void visit(GreaterThan *);
    virtual void visit(EqualTo *);
    virtual void visit(If *);
    virtual void visit(While *);
    virtual void visit(Block *);
    virtual void visit(SList *);
    virtual void visit(Assign *);
    virtual void visit(Declaration *);
    virtual void visit(Read *);
    virtual void visit(Write *);
    virtual void visit(Pass *);
    
    // You MUST keep all the function prototypes above.  You can
    // also add any addition functions and data as needed.
    int node_value;
};

#endif
