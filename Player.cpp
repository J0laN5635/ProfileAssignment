#include "Player.h"
#include <string.h>
#include <iostream>
#include "iostreamutils.h"

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
	cinclear(); // Clear Pending Input and error flags
	
	cout << "Enter Player Name> ";
	cin >> name;
	cout << "Enter Player Score> ";
	cin >> highScore;

	if (highScore > MaxScore)
		highScore = MaxScore;

	return true;


}

bool Player::operator<(const Player& other) const
{
	return (highScore < other.highScore);
}

