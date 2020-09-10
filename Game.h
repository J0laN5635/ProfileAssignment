#pragma once
#include "Leaderboard.h"
class Game
{
public:
	//Constructor
	Game();

	//Run Main Loop
	void Run();


private:
	virtual void Init() = 0;


	Leaderboard leaderboard;
};

