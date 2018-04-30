#include <vector>
#include <string>

using namespace std;

namespace Actions
{
	void testAction(vector<string> *vals); // pass a server connector to the current client!
	void registerClientAction(vector<string> *vals);
	void sendMessageToClientAction(vector<string> *vals);
}
