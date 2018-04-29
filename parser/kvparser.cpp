#include <cstring>
#include <iostream>

#include "kvparser.hpp"

//#define KVP_DEBUG

using namespace std;

void KVParser::clear_buffer()
{
	keybuf.clear();
	valbuf.clear();
}

void KVParser::buffer_append(char *c)
{
	switch(state)
	{
		case KEY:
			keybuf += *c;
			break;
		case VALUE:
			valbuf += *c;
			break;
	}
}

void KVParser::process_char(char *c)
{
	#ifdef KVP_DEBUG
	printf("processing character '%c'\n",*c);
	#endif
	switch(*c)
	{
		#ifdef KVP_DEBUG
		printf("got set delim\n");
		#endif
		case SET_DELIMITER:
			state = VALUE;
			break;
		case PAIR_DELIMITER:
			state = KEY;
			values.insert(pair<string,string>(keybuf,valbuf));
			clear_buffer();
			break;
		default:
			#ifdef KVP_DEBUG
			printf("Appending '%c' to buffer\n",c);
			#endif
			buffer_append(c);
			break;
	}
}

void KVParser::parse(char *c)
{
	state = KEY;
	values.clear();
	clear_buffer();
	for(int i = 0; i < strlen(c); ++i)
	{
		process_char(c+i);
	}
	values.insert(pair<string,string>(keybuf,valbuf));
}

