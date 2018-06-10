#include "node.h"
#include <iostream>
#include <string>

using namespace std;

class LinkedList { //This is a linked list. It works simply by indexing the tail of the node
public:

	node * tail = nullptr;

	LinkedList()
	{

	}

	void Add(string name, int val, int scope) //Works by simply changing the tail to the new node
	{
		tail = new node(name, val, scope, tail); //creates a new node consisting of a value and the index of the last tail
	}

	void Remove() //Removes the tail by setting it to the index of the link stored by the node
	{
		if (tail != nullptr)
		{
			tail = tail->getLink();
		}
	}

	node * search(string name, int scope)
	{
		node * traverse = tail;
		while (traverse != nullptr && traverse->name != name)
		{
			traverse = traverse->link;
			if (traverse == nullptr)
				return nullptr;
		}
		if (traverse != nullptr && traverse->scope <= scope)
			return traverse;
		else
			return nullptr;
	}

	node * getTail()
	{
		return tail;
	}
};
