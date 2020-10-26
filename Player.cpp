#include "Player.h"
#include <string.h>
#include <iostream>

using namespace std;

Player::Player(const char* _name, unsigned int highscore)
{
	strcpy_s(this->name, MaxNameLength, _name);
	this->highScore = highscore;
}

void Player::Draw()
{
	cout << name << ": " << highScore << endl;
}

bool Player::LoadFromConsole()
{
	cin.ignore(cin.rdbuf()->in_avail()); // Clear Pending Input
	
	cout << "Enter Player Name> ";
	cin >> name;
	cout << "Enter Player Score> ";
	cin >> highScore;

	if (highScore > MaxScore)
		highScore = MaxScore;

	return true;

	// Tutorial May 22nd 2:08:50
}

