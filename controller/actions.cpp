#include <iostream>
#include "actions.hpp"

using namespace std;

void Actions::testAction(vector<string> *vals)
{
	cout << "TestAction: argument count: " << vals->size() << endl;
	uint8_t n = 0;
	for(string i : *vals)
	{
		printf("TestAction: argument no '%hu' = '%s'\n", n, i.c_str());
		++n;
	}
}
