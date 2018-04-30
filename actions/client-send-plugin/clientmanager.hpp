#include <map>
#include <string>
#include <cstdint>

using namespace std;

#pragma once

class ClientManager
{
	public:
		class client
		{
			public:
				uint16_t fd;
		};
	private:
		static map<string,client> clients;
	public:
		static void addClient(string name, client cl);
		static void sendMessageToClient(string message, string clientname);
};
