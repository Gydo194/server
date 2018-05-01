#include <vector>
#include <string>

#include "../server/Server.hpp"

using namespace std;

namespace Actions
{
	void testAction(Server::Connector conn, vector<string> *vals); // pass a server connector to the current client!
	void registerClientAction(Server::Connector conn, vector<string> *vals);
	void sendMessageToClientAction(Server::Connector conn, vector<string> *vals);
}
