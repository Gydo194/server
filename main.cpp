#include <iostream>
#include <cstdint>

#include "server/Server.hpp"
#include "controller/controller.hpp"
#include "misc/globals.hpp"

//declare the extern server
Server server;

int main(int argc, char **argv)
{
	//set server callbacks
	server.onConnect(&Controller::handleServerConnection);
	server.onDisconnect(&Controller::handleServerDisconnect);
	server.onInput(&Controller::handleServerInput);
	server.init();
	
	//actual main loop
	while(true)
	{
		server.loop();
	}
}
