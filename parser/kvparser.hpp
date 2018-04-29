#ifndef KVPARSER_HPP
#define KVPARSER_HPP

#include <cstring>
#include <iostream>
#include <map>

#define SET_DELIMITER '='
#define PAIR_DELIMITER '&'

using namespace std;

class KVParser
{
	private:
	enum states { KEY, VALUE };
	states state = KEY;
	string keybuf;
	string valbuf;

	void buffer_append(char *c);
	void process(char *c);
	void clear_buffer();

	public:
	map<string,string> values;
	//processes a character
	void process_char(char *buffer);
	//processes an array of characters
	void parse(char *buffer);
};

#endif
