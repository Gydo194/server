/*
 * parser.cpp
 * simple parser for gprpcd - function defenitions
 * original work by Gydo194
 */

#include <iostream>
#include <string>
#include <sstream>

#include "parser.hpp"

using namespace std;

void Parser::parse(char *buffer)
{
	parse((const char*)buffer);
}

void Parser::parse(const char *buffer)
{
	string in = buffer;
	istringstream iss(in);

	string sub;
	while(iss >> sub)
	{
		values.push_back(sub);
	}
}
