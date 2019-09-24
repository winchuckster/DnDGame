#pragma once

#include <string>

using namespace std;

class Items
{
private:
	string Name;
	bool CanBeTaken;
	int Value;
	string Interact;


public:
	Items(void);
	Items(string Name, bool CanBeTaken,	int value, string interact);
	~Items(void);
};

