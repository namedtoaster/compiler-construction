#ifndef ILOCEMITTER_H
#define ILOCEMITTER_H

#include <string>
#include <list>
#include <map>

#include "AST.h"

struct ILOCEmitter : public ASTVisitor
{
    ILOCEmitter();
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

    // Register iterator
    int reg_num;

    // Symbol table; var -> reg_num
    std::list< std::map< std::string, int > > sym_t;

    // Symbol table entry
    std::map< std::string, int > entry;

    // Symbol table; reg_num -> value
    std::list < std::map< int, int > > sym_t_val;

    // Symbol table entry
    std::map< int, int > entry_val;

    int result;
    int label_num;

};

#endif
