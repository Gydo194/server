#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstring>
#include <cstdint>
#include <map>
#include <vector>

#include "../server/Server.hpp"

using namespace std;

namespace Controller
{
	typedef void (*handler)(Server::Connector conn, vector<string> *args);

	void addHandler(string key, handler h);
	void removeHandler(string key);

	void handleServerConnection(Server::Connector conn);
	void handleServerDisconnect(Server::Connector conn);
	void handleServerInput(Server::Connector conn, char *buffer);

	void handleRequest(string name);
}

#endif //CONTROLLER_H header guard
