#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector< int > > array;

	std::vector< int > first;
	first.push_back(1);
	first.push_back(2);

	array.push_back(first);

	std::vector< int > second;
	second.push_back(3);

	array.push_back(second);

	return 0;
}