#include <iostream>
#include <cstddef>

using namespace std;

class node { //This is a node. It helps construct a linked list.
public:
	string name;
	int value; //The value stored by the node
	int scope;
	node * link; //Link is the pointer to the item in the list before the tail
	node(string n, int i, int s, node * nd)
	{
		name = n;
		value = i;
		scope = s;
		link = nd;
	}

	node * getLink()
	{
		return link;
	}

	int getValue()
	{
		return value;
	}

};