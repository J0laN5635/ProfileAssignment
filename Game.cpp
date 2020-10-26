#include "Game.h"
#include "Leaderboard.h"

Game::Game()
{

};

void Game::Run()
{
	Init();
	
	while (IsGameRunning())
	{
		Draw();
		Update();
	}

	Shutdown();
}