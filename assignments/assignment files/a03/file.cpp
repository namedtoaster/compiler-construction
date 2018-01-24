#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

bool is_op(char value)
{
	if (value == 42 || value == 43 || value == 45 || value == 47)
		return true;
	return false;
}

bool is_less_than_or_eq(char value1, char value2)
{
	if (value1 == '/' || value1 == '*')
	{
		if (value2 == '+' || value2 == '-')
			return false;
	}
	return true;
}

int main(int argc, char * argv[])
{
	vector< char > cv;
	vector< string >name;
	string input_line;

	getline(cin, input_line);
	for (int i = 0; i < input_line.size(); i++) {
		if (input_line[i] != ' ') {
			cv.push_back(input_line[i]);
		}
	}

	// Shunting yard algorithm
	stack<char> op_stack;
	vector<char> output;

	for (int i = 0; i < cv.size(); i++)
	{
		if (cv[i] >= '1' && cv[i] <= '9')
		{
			output.push_back(cv[i]);
		}
		else if (is_op(cv[i]))
		{
			if (op_stack.size() == 0)
				op_stack.push(cv[i]);
			else
			{
				if (is_less_than_or_eq(cv[i], op_stack.top()))
				{
					for (int j = op_stack.size(); j > 0; j--)
					{
						if (is_less_than_or_eq(cv[i], op_stack.top()) && op_stack.top() != '(')
						{
							output.push_back(op_stack.top());
							op_stack.pop();
						}
						else
							break;
					}
					op_stack.push(cv[i]);
				}
				else
				{
					op_stack.push(cv[i]);
				}
			}
		}
		else if (cv[i] == '(')
		{
			op_stack.push(cv[i]);
		}
		else if (cv[i] == ')')
		{
			for (int j = op_stack.size(); j > 0; j--)
			{
				if (op_stack.top() != '(')
				{
					output.push_back(op_stack.top());
					op_stack.pop();
				}
				else
					break;
			}
			op_stack.pop();
		}
	}

	for (int i = 0; i < name.size(); i++)
		cout << name[i] << ' ';

	// Add the extra operators onto the end of the output stream
	for (int i = 0; i < op_stack.size(); i++)
	{
		output.push_back(op_stack.top());
		op_stack.pop();
		if (op_stack.size() == 1)
			output.push_back(op_stack.top());
	}

	// Print the output stream
	for (int i = 0; i < output.size(); i++)
		cout << output[i];

	// Create names for nodes
	for (int i = 0; i < output.size(); i++)
	{
		stringstream out;
		out << i;
		name.push_back("n" + out.str());
	}

	ofstream file;
	file.open("graph.dot");
	file << "digraph G {\n\t";
	file.close();
	file.open("graph.dot", ios::app);

	stack<string> label;

	// Label the values of the nodes
	for (int i = 0; i < name.size(); i++)
	{
		file << name[i] << " [label = \"" << output[i] << "\"]\n\t";
	}

	// Used notes from http://www.docstoc.com/docs/55696108/Chapter-9-binary-tree
	// Create the tree
	for (int i = 0; i < output.size(); i++)
	{
		if (!is_op(output[i]))
		{
			label.push(name[i]);
		}
		else
		{
			file << name[i] << " -> " << label.top() << "\n\t";
			label.pop();
			file << name[i] << " -> " << label.top() << "\n\t";
			label.pop();
			label.push(name[i]);
		}
	}

	file << "\n}";
	file.close();

	return 0;
}