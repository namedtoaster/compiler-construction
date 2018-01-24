#include <iostream>

#include "AST.h"
#include "ILOCEmitter.h"

using namespace std;


ILOCEmitter::ILOCEmitter() : reg_num(0), label_num(0) {}

void ILOCEmitter::visit(Number * n)
{
	// Print the ILOC code
	std::cout << "\nloadI " << n->num << " -> r" << reg_num;

	// Put the register number into the result variable for later use
	result = reg_num;
}

void ILOCEmitter::visit(Plus * p)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	p->lhs->accept(this);
	int left = result;

	p->rhs->accept(this);
	int right = result;

	std::cout << "\nadd r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(Minus * m)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	m->lhs->accept(this);
	int left = result;

	m->rhs->accept(this);
	int right = result;

	std::cout << "\nsub r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(Times * t)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	t->lhs->accept(this);
	int left = result;

	t->rhs->accept(this);
	int right = result;

	std::cout << "\nmult r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(Divide * d)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	d->lhs->accept(this);
	int left = result;

	d->rhs->accept(this);
	int right = result;

	std::cout << "\ndiv r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(LessThan * d)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	d->lhs->accept(this);
	int left = result;

	d->rhs->accept(this);
	int right = result;

	std::cout << "\ncomp_LT r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(GreaterThan * d)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	d->lhs->accept(this);
	int left = result;

	d->rhs->accept(this);
	int right = result;

	std::cout << "\ncomp_GT r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(EqualTo * d)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	d->lhs->accept(this);
	int left = result;

	d->rhs->accept(this);
	int right = result;

	std::cout << "\ncomp_EQ r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(Id * i)
{
	// Scan the scope; the only time this function will run is if
	// a variable is being called as an argument to an expression.
	//
	// If a variable is not found in the current scope, previous
	// scopes will be scanned.
	//
	// If the variable is never found, there is something wrong
	// with the tiny program and the program will not run.
	//
	// There is no error output, so the program will just crash.
	if (!entry[i->text])
	{
		// First, copy the symbol table to be modified
		std::list< std::map< std::string, int > > copy = sym_t;
		for (int x = sym_t.size() - 1; x >= 0; x--)
		{
			// If the variable is found, assign it to the current
			// symbol table and end the loop.
			if (copy.front()[i->text])
			{
				entry[i->text] = copy.front()[i->text];
				break;
			}
			// If the variable doesn't exist in current scope, pop
			// off the first table and move on to previous ones.
			copy.pop_front();
		}
		reg_num--;
	}

	// Put the register number into the result variable for later use
	result = entry[i->text];
}

void ILOCEmitter::visit(If * f)
{
	// You must accept both sides before doing anything
	//
	// You must place the numbers into registers before you do any
	// operation
	f->test->accept(this);
	//int left = result;

	//f->rhs->accept(this);
	//int right = result;

	//std::cout << "\ncomp_EQ r" << left << ", r" << right << " -> r" << ++reg_num;
}

void ILOCEmitter::visit(While * w)
{
	// Print out the label
	std::cout << "\nlabel" << label_num << ": nop";

	// Accept the conditional
	w->test->accept(this);

	// Finish writing code to determine if the loop will continue or not
	std::cout << "\ncbr r" << reg_num << " -> label"; ++label_num;
	std::cout << label_num;

	std::cout << ", label"; ++label_num;
	std::cout << label_num;

	std::cout << "\nlabel" << label_num - 1 << ": nop";

	// Increase the register number
	reg_num++;std::cout << "\n" << reg_num << "\n";

	// Accept the body
	w->body->accept(this);
}

void ILOCEmitter::visit(Block * b)
{
	// Add a new layer to the symbol table, while clearing
	// the current scope
	sym_t.push_front(entry);
	entry.erase(entry.begin(), entry.end());

	// Accept the block and continue
	b->first->accept(this);
}

void ILOCEmitter::visit(SList * s)
{
	// Accept the first part of the SList
	s->first->accept(this);

	// Accept the second part of the SList
	s->rest->accept(this);
}

void ILOCEmitter::visit(Declaration * d)
{
	// Accept the expression
	d->expr->accept(this);

	// Write the ILOC code that will assign the expression to the 
	// var being assigned
	std::cout << "\ni2i r" << reg_num << " -> r";

	// Add an entry to the symbol table
	std::cout << (entry[d->name->text] = ++reg_num) << std::endl;
	reg_num++;
}

void ILOCEmitter::visit(Assign * a)
{
	// Accept the expression
	a->expr->accept(this);

	// Write the ILOC code that will assign the expression to the 
	// var being assigned
	std::cout << "\ni2i r" << reg_num << " -> r";

	// Accept the var receiving the value
	a->name->accept(this);

	std::cout << entry[a->name->text];// << std::endl;
}

void ILOCEmitter::visit(Read * r)
{
	// Simply read a value; the register will be determined by the var
	// that is being read
	std::cout << "\nread r";

	// Accept the var being read
	r->name->accept(this);

	std::cout << entry[r->name->text];// << std::endl;
}

void ILOCEmitter::visit(Write * w)
{
	// Simiply write a value; the register will be determined by the
	// var that is being written
	std::cout << "\nwrite r";

	// Accept the var being written
	w->name->accept(this);

	std::cout << entry[w->name->text] << std::endl;
}

void ILOCEmitter::visit(Pass *)
{
	std::cout << "Pass" << std::endl;
}
