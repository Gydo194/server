#include <iostream>
#include <cstring>

#include "controller.hpp"

#include "../parser/kvparser.hpp"
#include "../misc/globals.hpp"

using namespace std;

KVParser kvp;

void Controller::handleServerConnection(uint16_t fd)
{
	cout << "Controller: got connect from " << fd << endl;
}

void Controller::handleServerDisconnect(uint16_t fd)
{
	cout << "Controller: got disconnect from " << fd << endl;
}

void Controller::handleServerInput(uint16_t fd, char *buffer)
{
	cout << "Controller: got input '" << buffer << "'from " << fd << endl;
	kvp.parse(buffer);
	map<string,string>::iterator it = kvp.values.begin();
	for(;it != kvp.values.end(); ++it)
	{
		cout << "Controller: Key: '" << it->first << "' val '" << it->second << "'\n";
	}
	cout << "Controller: done handling input\n";
}
