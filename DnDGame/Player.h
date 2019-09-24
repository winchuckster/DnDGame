#pragma once
#include <string>
#include <vector>
#include "Items.h"
using namespace std;

class Player
{
private:
	int hitPoints;
	string name;
	int strength; // may make struct later
	int dexterity; 
	int constitution; 
	int intelligence;
	int wisdom;
	int charisma;
	vector<Items> inventory;


public:
	Player(void);
	Player(int hp);
	int GetHP(void);
	void SetAttributes(string name, int str, int dex, int cons, int intel, int wis, int cha);
	string PrintAttributes();
	~Player(void);
	
};

