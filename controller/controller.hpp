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
//	map<string,handler> handlers;

	void addHandler(string key, handler h);
	void removeHandler(string key);

	void handleServerConnection(uint16_t fd);
	void handleServerDisconnect(uint16_t fd);
	void handleServerInput(uint16_t fd, char *buffer);

	void handleRequest(string name);
}

#endif //CONTROLLER_H header guard
