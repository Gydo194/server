#include <iostream>
#include "actions.hpp"
#include "client-send-plugin/clientmanager.hpp"

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

void Actions::registerClientAction(vector<string> *vals)
{
	string name;
	try
	{
		name = vals->at(1);
		ClientManager::client c;
		c.fd = 4;
		ClientManager::addClient(name,c);
	}
	catch(out_of_range oor)
	{
		cerr << "RegisterClientAction: no register name (at(1) failed)\n";
	}
}

void Actions::sendMessageToClientAction(vector<string> *vals)
{
	string clientname = "DEFAULT_CLIENT_NAME";
	string message = "DEFAULT_MESSAGE_CONTENT";

	try
	{
		message = vals->at(1);
		clientname = vals->at(3);
		cout << "Sending message '" << message << "' to client name '" << clientname << "'.\n";
		ClientManager::sendMessageToClient(message,clientname);
	}
	catch(out_of_range oor)
	{
		cerr << "Actions::SendMessageToClient(): out_of_range in param get\n";
	}
}
