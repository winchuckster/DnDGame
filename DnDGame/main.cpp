// DnDGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Game* game = new Game();
	game->Run();
	

	return 0;
}

