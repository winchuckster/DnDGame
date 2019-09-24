#include "stdafx.h"
#include "Items.h"


Items::Items(void)
{
}

Items::Items(string name, bool canBeTaken, int value, string interact)
{
	Name = name;
	CanBeTaken = canBeTaken;
	Value = value;
	Interact = interact;
}


Items::~Items(void)
{
}
