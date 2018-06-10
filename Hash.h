#include "LinkedList.h"

#define TBLSize 10

class Hash
{
public:
	LinkedList * hash[TBLSize];

	Hash()
	{
		for (int x = 0; x < TBLSize; x++) // Yes, I am doing it like this because I forgot how to do it the other way
		{
			hash[x] = new LinkedList(); // initializes our Linked Lists
		}
	}

	int hashFunction(string name)
	{
		int total = 0;
		for (int i = 0; i < name.size(); i++) {
			total = name[i] * (i + 1);
		}

		return total % TBLSize;

	}

	void Add(string name, int val, int scope)
	{
		int key = hashFunction(name);
		hash[key]->Add(name, val, scope);
	}

	node * Search(string name, int scope)
	{
		int key = hashFunction(name);
		return hash[key]->search(name, scope);
	}
};
