#include <iostream>
#include <cstring>
#include <map>

#include "controller.hpp"
#include "../parser/parser.hpp"
#include "../misc/globals.hpp"
#include "../misc/map_get.hpp"
#include "../server/Server.hpp"

using namespace std;

Parser prs;
map<string,Controller::handler> handlers;

void Controller::handleServerConnection(Server::Connector conn)
{
	cout << "Controller: got connect from " << conn.source_fd << endl;
}

void Controller::handleServerDisconnect(Server::Connector conn)
{
	cout << "Controller: got disconnect from " << conn.source_fd << endl;
}

void Controller::handleServerInput(Server::Connector conn, char *buffer)
{
	cout << "Controller: got input '" << buffer << "'from " << conn.source_fd << endl;
	prs.parse(buffer);
	for(string i : prs.values)
	{
		cout << "Controller::handleServerInput -> for: input: '" << i << "'.\n";
	}


	//get the first argument name
	string key;
	try
	{
		key = prs.values.at(0);
	}
	catch(out_of_range oor)
	{
		cerr << "no action" << endl;
	}

	//look it up in the handlers map
	Controller::handler h = NULL;
	if(map_get<string,Controller::handler>(&handlers, key, &h))
	{
		printf("Controller: handler address = '%x'\n",h);
		//call the callback function
		h(conn, &prs.values);
	}
	else
	{
		cerr << "[ERROR] Controller: No such action (" << key << ")\n";
	}

	prs.values.clear();
}

void Controller::addHandler(string key, Controller::handler cb)
{
	handlers.insert(pair<string,Controller::handler>(key,cb));
}

void Controller::removeHandler(string key)
{
	cout << "Controller::removeHandler: key=" << key << endl;
}
