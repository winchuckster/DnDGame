#pragma once

#include <string>
#include <vector>
#include "Monster.h"
#include "Items.h"

using namespace std;

class Room
{
private:
	string description;
	//int doors[4];	// 0 for open, 1 for locked, 2 for no door
					// four spaces for NESW
	string doors[2];
	Room* nextRoom;
	Room* lastRoom;
	Monster monster;
	vector<Items> items;

public:
	Room(void);
	Room(string description, string doors[2], Monster monster, vector<Items> items);
	string ReadDescription();
	string DoorDescription();
	void SetLastRoom(Room* LastRoom);
	void SetNextRoom(Room* NextRoom);
	Room* GetLastRoom();
	Room* GetNextRoom();
	string NextDoor();
	string LastDoor();
	~Room(void);
};

