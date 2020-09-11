#pragma once
#include "Game.h"
#include "Leaderboard.h"

class PlayerDatabase:
	public Game
{
public:

protected:
	//Game Overrides
	virtual void Init() override;
	virtual void Shutdown() override;
	virtual bool IsGameRunning() override;

	virtual void Update() override;
	virtual void Draw() override;

private:
	enum class MenuOption
	{
		Quit,
		NewPlayer
	};

	bool isGameRunning = true;
	Leaderboard leaderboard;

	void displayerMenu();
	MenuOption getMenuOption();

};

