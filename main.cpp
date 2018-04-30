#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

#include "server/Server.hpp"
#include "controller/controller.hpp"
#include "misc/globals.hpp"
#include "actions/actions.hpp"

//declare the extern server
Server server;

void attachActions()
{
	Controller::addHandler("test",Actions::testAction);
	Controller::addHandler("send",Actions::sendMessageToClientAction);
	Controller::addHandler("register",Actions::registerClientAction);
}

int main(int argc, char **argv)
{
	//add controller actions
	attachActions();
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
