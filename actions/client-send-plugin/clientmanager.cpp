#include <map>
#include <string>
#include <iostream>

#include "clientmanager.hpp"
#include "../../misc/map_get.hpp"

map<string,ClientManager::client> ClientManager::clients;

void ClientManager::addClient(string name, client cl)
{
	clients.insert(pair<string,ClientManager::client>(name,cl));
}

void ClientManager::sendMessageToClient(string message, string clientname)
{
	client cl;
	cl.fd = 0;
	if( map_get<string,client>(&clients, clientname, &cl) )
	{
		cout << "Send Message: '" << message << "' to clientfd '" << cl.fd << "'\n";
	}
	else
	{
		cerr << "ClientManager::send: map_get failed\n";
	}
}
