#include <map>
#include <string>
#include <iostream>

#include "clientmanager.hpp"
#include "../../misc/map_get.hpp"
#include "../../misc/globals.hpp"

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
		Server::Connector conn;
		conn.source_fd = cl.fd;
		server.sendMessage(conn,message.c_str());
	}
	else
	{
		cerr << "ClientManager::send: map_get failed\n";
	}
}
