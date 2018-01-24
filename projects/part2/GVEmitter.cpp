#include <iostream>

#include "AST.h"
#include "GVEmitter.h"

using std::cout;
using std::endl;

// You MUST fill in implementation for each of these functions, plus
// any additional function that you define in GVEmitter.h
//
// You will probably do a lot of cut-and-paste; many node types behave
// very similarly.  Think about adding additional functions to cut down
// on the repetition.

GVEmitter::GVEmitter() : node_value(0) {}

void GVEmitter::visit(Number * n)
{
	// Set the value of the number
	std::cout << "n" << node_value << " [label = \"" << n->num << "\"]" << std::endl;
}


void GVEmitter::visit(Plus * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"+\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}


void GVEmitter::visit(Minus * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"-\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}


void GVEmitter::visit(Times * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"*\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}


void GVEmitter::visit(Divide * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"/\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}


void GVEmitter::visit(Id * id)
{
	// Set the name of the Id
	std::cout << "n" << node_value << " [label = \"" << id->text << "\"]" << std::endl;
}


void GVEmitter::visit(LessThan * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"<\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}

void GVEmitter::visit(GreaterThan * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \">\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}

void GVEmitter::visit(EqualTo * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \":=\"]" << std::endl;
	
	// Accept the left hand side (lhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->lhs->accept(this);

	// Accept the right hand side (rhs); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rhs->accept(this);
}

void GVEmitter::visit(If * ifNode)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"if\"]" << std::endl;
	
	// Accept the conditional (test); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	ifNode->test->accept(this);

	// Accept the if true node (ifTrue); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	ifNode->ifTrue->accept(this);

	// Accept the if true node (ifFalse); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	ifNode->ifFalse->accept(this);
}

void GVEmitter::visit(While * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"while\"]" << std::endl;

	// Accept the conditional (test) side; increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->test->accept(this);

	// Accept the body; increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->body->accept(this);
}

void GVEmitter::visit(Block * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \"block\"]" << std::endl;

	// Accept the SList (first); increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->first->accept(this);
}

void GVEmitter::visit(SList * n)
{
	int node_id = node_value;

	// Set up the node
	std::cout << "n" << node_id << " [label = \";\"]" << std::endl;	

	// Accept the left (first) side; increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	n->first->accept(this);

	// Accept the right (rest) side; increment the node number first
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	n->rest->accept(this);
}

void GVEmitter::visit(Assign * a)
{
	int node_id = node_value;
	// Set up the node
	std::cout << "n" << node_id << " [label = \":=\"]" << std::endl;
	
	// Set left side (var being declared) and accept
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	a->name->accept(this);

	// Set the right side (value being assigned) and accept
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	a->expr->accept(this);
}

void GVEmitter::visit(Declaration * a)
{
	int node_id = node_value;
	// Set up the node
	std::cout << "n" << node_id << " [label = \"var\"]" << std::endl;
	
	// Set left side (var being declared) and accept
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_id + 1 << std::endl;
	a->name->accept(this);

	// Set the right side (value being assigned) and accept
	node_value++;
	std::cout << "n" << node_id << "-> n" << node_value << std::endl;
	a->expr->accept(this);
}

void GVEmitter::visit(Read * r)
{
	// Set up the node
	std::cout << "n" << node_value << " [label = \"read\"]" << std::endl;
	
	// Set the var being read
	std::cout << "n" << node_value << "-> n" << node_value + 1 << std::endl;

	// Accept the node
	node_value++;
	r->name->accept(this);
}

void GVEmitter::visit(Write * w)
{
	// Set up the node
	std::cout << "n" << node_value << " [label = \"write\"]" << std::endl;
	
	// Set the var being written
	std::cout << "n" << node_value << "-> n" << node_value + 1 << std::endl;

	// Accept the node
	node_value++;
	w->name->accept(this);
}

void GVEmitter::visit(Pass * w)
{
	// Set up the node and accept right away. Do-nothing function

	std::cout << "n" << node_value << " [label = \"pass\"]" << std::endl;
	
	//w->accept(this);
	// This caused the program to crash when running cat tests/test2.txt | ./tiny > out2.gv
	// Passed the test, so I'm not sure if the accept function
	// was neccessary for the Pass variable.
}
