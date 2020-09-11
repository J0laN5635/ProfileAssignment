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
	virtual void Shutdown() = 0;
	virtual bool IsGameRunning() = 0;

	virtual void Update() = 0;
	virtual void Draw() = 0;
};


