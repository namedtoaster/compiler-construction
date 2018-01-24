#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Received assistance on creating this class
// from Ujjwal
class Node{
public:
	Node(int d, Node *p=NULL, Node *l=NULL, Node *r=NULL) 
	: data(d), parent(p), left(l), right(r) {}

	int get_data() const
	{
		return data;
	}
	void set_data(int value)
	{
		data = value;
	}
	void set_parent(Node * value)
	{
		parent = value;
	}
	void set_right(Node * value)
	{
		right = value;
	}
	void set_left(Node * value)
	{
		left = value;
	}

	Node * get_parent() const
	{
		return parent;
	}
	Node * get_left() const
	{
		return left;
	}
	Node * get_right() const
	{
		return right;
	}
private: 
	int data;
	Node *parent;
	Node *left;
	Node *right;
};

bool exists(int length, int array[], int value)
{
	for (int i = 0; i < length; i++)
	{
		if (value == array[i])
			return true;
	}

	return false;
}

void print(int array[], int length)
{
	for (int i = 0; i < length; i++)
		cout << array[i] << endl;
	cout << endl;
}

void print(Node * node)
{
	if (node->get_left() != NULL)
		print(node->get_left());
	cout << node->get_data() << " ";
	if (node->get_right() != NULL)
		print(node->get_right());
}

void make_graph(Node * node)
{
	if (node->get_left() != NULL)
	{
		ofstream file;
		file.open("BST.dot", fstream::app);
		file << node->get_data() << "->" << node->get_left()->get_data() << ";\n";
		file.close();

		make_graph(node->get_left());
	}
	if (node->get_right() != NULL)
	{
		ofstream file;
		file.open("BST.dot", fstream::app);
		file << node->get_data() << "->" << node->get_right()->get_data() << ";\n";
		file.close();

		make_graph(node->get_right());
	}
}

Node * make_tree(Node * node, int array[], int length)
{
	int root;
	Node * parent = NULL;
	if (length != 1)
		root = array[length / 2];
	else
	{
		node->set_data(array[0]);
		node->set_parent(parent);
		node->set_right(NULL);
		node->set_left(NULL);
		return node;
	}
	node->set_data(root);
	node->set_parent(parent);

	int l_right, l_left;
	if (length > 1) l_left = length / 2; else l_left = -1;
	if (length > 2) l_right = (length % 2 != 0 ? length / 2 : (length / 2) - 1); else l_right = -1;

	if (l_left != -1)
	{
		int * node_left = new int[l_left];
		int end_index = length / 2;
		for (int i = 0; i < end_index; i++)
			node_left[i] = array[i];
		Node * left = new Node(0);
		node->set_left(make_tree(left, node_left, l_left));
	}
	if (l_right != -1)
	{
		int * node_right = new int[l_right];
		int start_index = length / 2 + 1;
		for (int i = start_index, j = 0; i < length; i++, j++)
			node_right[j] = array[i];
		Node * right = new Node(0);
		node->set_right(make_tree(right, node_right, l_right));
	}

	return node;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	// Get the size
	int length = atoi(argv[1]);
	// Set the max range
	int RANGE = length;

	// Create random array
	int *random;
	random = new int[length];

	// Get values
	for (int i = 0; i < length; i++)
	{
		int t = rand() % RANGE + 1;
		if (i > 0)
		{
			while (exists(i, random, t))
			{
				t = rand() % RANGE + 1;
			}
		}
		random[i] = t;
	}

	// Sort array
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (random[j] > random[j + 1])
			{
				int t = random[j];
				random[j] = random[j + 1];
				random[j + 1] = t;
			}
		}
	}
	
	// Create the tree (set the root and recursivelly set left and right sides)
	Node *node = new Node(0);
	node = make_tree(node, random, length);

	ofstream myfile;
	myfile.open("BST.dot", ios::out);
	myfile << "digraph G{\n";
	myfile.close();

	make_graph(node);

	myfile.open("BST.dot", fstream::app);
	myfile << "\n}";
	myfile.close();

	return 0;
}