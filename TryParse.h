#include "stdafx.h"

template <class T> // Taken from https://www.daniweb.com/programming/software-development/threads/420579/gcc-equivalent-of-try-parse

bool TryParse(string input, T & var)
{
	static const string ws(" \t\f\v\n\r");
	size_t pos = input.find_last_not_of(ws);
	if (pos != string::npos)
		input.erase(pos + 1);
	else input.clear();
	stringstream buffer(input);
	return buffer >> var && buffer.eof();
}