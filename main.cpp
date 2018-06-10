// BORG Programming Language.cpp : Defines the entry point for the console application.
//Created by Paul Mandal, starting on 11/26/2016

#include "stdafx.h"
#include "TryParse.h"
#include <vector>
#include <math.h>
#include <fstream>

int scope = 0;
Hash * vars = new Hash();

void EVAL(string input) //Borrowing a trick that Lisp Interpreters use
{
	for (int i = 0; i < input.size(); i++)
	{
		char c = input[i];
		c = toupper(c);
		input[i] = c; //If I don't do it like this, I get a number
	}
	stringstream str(input);
	string buffer;
	vector<string> line;
	while (str >> buffer)
	{
		line.push_back(buffer);
	};
	
	if (line.at(0) == "COM")
	{
	//Ignore
	}

	else if (line.at(0) == "START")
	{
		scope++;
	}

	else if (line.at(0) == "FINISH")
	{
		scope--;
	}

	else if (line.at(0) == "VAR")
	{
		if (line.size() == 1)
		{
			cout << "Error: invalid syntax\n";
		}

		/*else if (vars->Search(line.at(1), scope) != nullptr)
		{
			cout << "Error: cannot have two variables with the same name\n";
		}*/
		
		else if (line.size() == 2)
		{
			vars->Add(line.at(1), NULL, scope);
		}

		else if (line.size() == 4 && line.at(2) == "=")
		{
			double val;
			if (TryParse(line.at(3), val))
			{
				vars->Add(line.at(1), val, scope);
			}

			else
			{
				cout << "Error: variables must store integers \n";
			}
		}

		else {
			cout << "Error, invalid syntax\n";
		}
	}

	else if (line.at(0) == "PRINT")
	{
		if (vars->Search(line.at(1), scope) == nullptr)
		{
			cout << "Error: " << line.at(1) << " is undefined\n";
		}
		else if (vars->Search(line.at(1), scope)->scope > scope)
		{
			cout << "Error: " << line.at(1) << " is undefined\n";
		}
		else if (line.size() == 2)
		{
			cout << line.at(1) << " is " << vars->Search(line.at(1), scope)->value << endl;
		}

		else if (line.size() == 4)
		{
			cout << line.at(1) << " " << line.at(2) << " " << line.at(3) << " is ";
			int value = vars->Search(line.at(1), scope)->value;
			int i;
			if (TryParse(line.at(3), i))
			{
				if (line.at(2) == "+")
					cout << value + i << endl;

				if (line.at(2) == "-")
					cout << value - i << endl;

				if (line.at(2) == "*")
					cout << value * i << endl;

				if (line.at(2) == "/")
					cout << value / i << endl;

				if (line.at(2) == "^")
					cout << pow(value, i) << endl;
			}

		}	
	}

	else if (vars->Search(line.at(0), scope) != nullptr)
	{
		if (line.at(1) == "++")
			vars->Search(line.at(0), scope)->value = vars->Search(line.at(0), scope)->value + 1;

		if (line.at(1) == "--")
			vars->Search(line.at(0), scope)->value = vars->Search(line.at(0), scope)->value - 1;

		if (line.at(1) == "=")
			vars->Search(line.at(0), scope)->value = stoi(line.at(2));

	}
}

int main()
{
	ifstream myfile("source.txt");
	string s;
	while (getline(myfile, s))
		EVAL(s);
	myfile.close();
	cout << "\n\n";
	string in;
	do
	{
		getline(cin, in);
		EVAL(in);
	} while (true);

}

