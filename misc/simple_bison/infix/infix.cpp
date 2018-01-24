#include <iostream>

int yyparse();

using namespace std;


int main()
{
	cout << "digraph G{\n";
    yyparse();
    cout << "}";
}
