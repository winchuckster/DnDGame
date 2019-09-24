#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Room.h"
#include "Monster.h"
#include "Items.h"

using namespace std;

class Game
{
private:
	Room* map[3][3];
	//int map[3][3];
	vector<Room*> possibleRooms;
	//Room*** map;

public:
	Game(void);
	void Run();
	void PrintIntro(void);
	void InitializePlayer(void);
	void InitializeMap();
	void GenerateRooms();
	void PlayGame();

	~Game(void);
};

