#include "stdafx.h"
#include "Game.h"



Game::Game(void)
{
}

void Game::Run(void)
{
	PrintIntro();
	//InitializePlayer();	
	GenerateRooms();
	InitializeMap();
	PlayGame();
	system("pause");
}

void Game::PrintIntro(void)
{
	cout << "Welcome to my game!" << endl;
}

void Game::InitializePlayer(void)
{
	Player* me = new Player();
	cout << "Would you like to make your own character or use the template?" << endl;
	cout << "Enter 0 for your own character or 1 for the template" << endl;
	int choice; 
	string name; 
	int strength, dexterity, constitution, intelligence, wisdom, charisma;
	cin >> choice;

	while((choice != 0) && (choice != 1))
	{
		cout << "I don't understand. Enter 0 for your own character or 1 for the template" << endl;
		cin >> choice;
	}
	if(!choice)
	{
		cout << "Alright, let's start rolling. But first, what is your character's name?" << endl;
		cin >> name; 
		cout << "Now let's pick their strength: " << endl;
		cin >> strength;
		cout << "Now let's pick their dexterity: " << endl;
		cin >> dexterity;
		cout << "Now let's pick their constitution: " << endl;
		cin >> constitution;
		cout << "Now let's pick their intelligence: " << endl;
		cin >> intelligence;
		cout << "Now let's pick their wisdom: " << endl;
		cin >> wisdom;
		cout << "Now let's pick their charisma: " << endl;
		cin >> charisma;
		me->SetAttributes(name, strength, dexterity, constitution, intelligence, wisdom, charisma);
		
	}
	else
	{
		me->SetAttributes("test!", 1,2,3,4,5,6);
	}
	string ans;
	cout << "Would you like to see your character's stats? Y/N" << endl;
	cin >> ans;
	if(ans == "Y")
	{
		cout << me->PrintAttributes();
	}

	system("pause");

	// call parameterized constructor with name, hp, and ability modifiers
	//Player* me = new Player();
	//Player* you = new Player(100);

	//cout << "player 1's hit points set to: " << me->GetHP() << endl;

	// choose your hero!
	// if choice == zubon OR case statement
	// set player == zubon stats and name
	// set others to NPCs

	//me->hitPoints = 5;

	//cout << "player 2's hit points set to: " << you->GetHP() << endl;
}

void Game::InitializeMap()
{	
	// vector of empty rooms and monster rooms
	// randomizer picks which one to take
	int k = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//Room* room = new Room();

			map[i][j] = possibleRooms[k];
			k++;
		}

	}



}

void Game::GenerateRooms()
{
	//	 _______ _______ _______
	//	|		|		|		|
	//	|	6	D	7	D	8	|
	//	 ___D___ _______ _______
	//	|		|		|		|
	//	|	5	D	4	D	3	|
	//	 _______ _______ ___D___
	//	|		|		|		|
	//	|	0	D	1	D	2	|
	//	 _______________________
	// start
	string desc0 = "An empty room that you start in";
	//int doors0[4] = {2, 0, 2, 2};	// door open in east
	string doors[2] = {"E"};
	Monster* monster = new Monster();
	vector<Items> items;
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc0,doors,*monster,items));
	possibleRooms[0]->SetLastRoom(NULL);

	//
	string desc1 = "A small room, second [1]";
	//int doors1[4] = {2, 0, 2, 0};	// open doors east and west	
	string doors1[2] = {"E","W"};	// open doors east and west	
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc1,doors1,*monster,items));
	possibleRooms[1]->SetLastRoom(possibleRooms[0]);
	possibleRooms[0]->SetNextRoom(possibleRooms[1]);

	string desc2 = "A small room, third [2]";
	//int doors2[4] = {0, 2, 2, 0};	// open doors north and west
	string doors2[2] = {"N","W"};	// open doors north and west
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc2,doors2,*monster,items));
	possibleRooms[2]->SetLastRoom(possibleRooms[1]);
	possibleRooms[1]->SetNextRoom(possibleRooms[2]);

	string desc3 = "A small room, fourth [3]";
	//int doors3[4] = {2, 2, 0, 0};	// open doors south and west
	string doors3[2] = {"W","S"};
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc3,doors3,*monster,items));
	possibleRooms[3]->SetLastRoom(possibleRooms[2]);
	possibleRooms[2]->SetNextRoom(possibleRooms[3]);

	string desc4 = "A small room, fifth [4]";
	//int doors4[4] = {2, 0, 2, 0};	// open doors east and west
	string doors4[2] = {"W","E"};
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc4,doors4,*monster,items));
	possibleRooms[4]->SetLastRoom(possibleRooms[3]);
	possibleRooms[3]->SetNextRoom(possibleRooms[4]);

	string desc5 = "A small room, sixth [5]";
	//int doors5[4] = {0, 0, 2, 2};	// open doors east and north
	string doors5[2] = {"N","E"};
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc5,doors5,*monster,items));
	possibleRooms[5]->SetLastRoom(possibleRooms[4]);
	possibleRooms[4]->SetNextRoom(possibleRooms[5]);

	string desc6 = "A small room, seventh [6]";
	//int doors6[4] = {2, 0, 0, 2};	// open doors south and east
	string doors6[2] = {"E","S"};
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc6,doors6,*monster,items));
	possibleRooms[6]->SetLastRoom(possibleRooms[5]);
	possibleRooms[5]->SetNextRoom(possibleRooms[6]);
	
	string desc7 = "A small room, eighth [7]";
	//int doors7[4] = {2, 1, 2, 0};	// open doors east and locked door west
	string doors7[2] = {"E","W"};
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc7,doors7,*monster,items));
	possibleRooms[7]->SetLastRoom(possibleRooms[6]);
	possibleRooms[6]->SetNextRoom(possibleRooms[7]);

	string desc8 = "A small room, ninth [8]";
	//int doors8[4] = {2, 2, 2, 0};	// open door west
	string doors8[2] = {"W"};
	items.push_back(Items("Quest scroll",true,0,"You pick up the scroll and it says: \"Welcome to my game, Adventurer!\""));	
	possibleRooms.push_back(new Room(desc8,doors8,*monster,items));
	possibleRooms[8]->SetLastRoom(possibleRooms[7]);
	possibleRooms[8]->SetNextRoom(NULL);

}

void Game::PlayGame()
{
	string userInput;
	Room* currentRoom;

	currentRoom = map[0][0];

	while(true)
	{
		cout << "You are in a " << currentRoom->ReadDescription() << " room." << endl;
		cout << currentRoom->DoorDescription() << endl; 

		cout << "What would you like to do? {Press E to go east}" << endl;
		cin >> userInput;
		if(userInput == currentRoom->NextDoor())
		{
			Room* temp;
			temp = currentRoom;
			currentRoom = temp->GetNextRoom();
		}
		else if(userInput == currentRoom->LastDoor())
		{
			Room* temp;
			temp = currentRoom;
			currentRoom = temp->GetLastRoom();
		}
		else
		{
			cout << "I didn't understand that, try again" << endl;
		}
	}
}


Game::~Game(void)
{
}
