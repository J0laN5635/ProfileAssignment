#include "Player.h"
#include <string.h>

Player::Player(const char* _name, unsigned int highscore)
{
	strcpy_s(this->name, MaxNameLength, _name);
	this->highScore = highscore;
}
