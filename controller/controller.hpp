#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstring>
#include <cstdint>

#include "../parser/kvparser.hpp"

using namespace std;

namespace Controller
{
//	KVParser kvp;
	void handleServerConnection(uint16_t fd);
	void handleServerDisconnect(uint16_t fd);
	void handleServerInput(uint16_t fd, char *buffer);
}

#endif //CONTROLLER_H header guard
