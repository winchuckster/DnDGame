#include "stdafx.h"
#include "Room.h"


Room::Room(void)
{
}

Room::Room(string Description, string Doors[2], Monster Monster, vector<Items> Items)
{
	description = Description;
	for(int i = 0; i < 2; i++)
	{
		doors[i] = Doors[i];
	}
	monster = Monster;
	items = Items;
}

string Room::ReadDescription()
{
	return description;
}

string Room::DoorDescription()
{
	string doorDesc;
	int doorsfound = 0;
	
	if(doors[1] == "")
		doorDesc = "There is a door to the ";
	else
		doorDesc = "There are doors to the ";
	
	if(doors[0] == "N") doorDesc += "north";
	else if(doors[0] == "E") doorDesc += "east";
	else if(doors[0] == "S") doorDesc += "south";
	else if(doors[0] == "W") doorDesc += "west";
	
	if(doors[1] == "") doorDesc += ".";
	else doorDesc += " and ";
	
	if(doors[1] == "N") doorDesc += "north.";
	else if(doors[1] == "E") doorDesc += "east.";
	else if(doors[1] == "S") doorDesc += "south.";
	else if(doors[1] == "W") doorDesc += "west.";
	
	/*
	if(doors[0] == 0) doorDesc += "north";
	if(doors[1] == 0) doorDesc += "east";
	if(doors[2] == 0) doorDesc += "south";
	if(doors[3] == 0) doorDesc += "west";
	*/
	return doorDesc;

}

void Room::SetLastRoom(Room* LastRoom)
{
	lastRoom = LastRoom;
}
	

void Room::SetNextRoom(Room* NextRoom)
{
	nextRoom = NextRoom;
}

Room* Room::GetLastRoom()
{
	return lastRoom;
}
	
Room* Room::GetNextRoom()
{
	return nextRoom;
}

string Room::NextDoor()
{
	return doors[0];
}
	
string Room::LastDoor()
{
	return doors[1];
}

Room::~Room(void)
{
}
