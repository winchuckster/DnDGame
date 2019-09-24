#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;


Player::Player(void)
{
	hitPoints = 10;
}

Player::Player(int hp)
{
	hitPoints = hp;


}

int Player::GetHP(void){
	return hitPoints;
}

void Player::SetAttributes(string Name, int str, int dex, int cons, int intel, int wis, int cha)
{
	name = Name;
	strength = str;
	dexterity = dex;
	constitution = cons;
	intelligence = intel;
	wisdom = wis;
	charisma = cha;
}
string Player::PrintAttributes()
{
	string printout;
	printout = "Name: " + name + "\n" + "Strength: " + to_string(strength) + "\n" + "Dexterity: " + 
		to_string(dexterity) + "\n" + "Constitution: " + to_string(constitution) + "\n" + "Intelligence: " + 
		to_string(intelligence) + "\n" + "Wisdom: " + to_string(wisdom) + "\n" + "Charisma: " + to_string(charisma) + "\n";
	return printout;
}

Player::~Player(void)
{
}
