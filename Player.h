#pragma once


class Player
{
public:
	static const unsigned int MaxScore = 69420;
	static const unsigned int MaxNameLength = 50;

	Player(const char* _name = "", unsigned int highscore =0);

	unsigned int GetHighScore() const { return highScore; }
	const char* GetName() const { return name; }

	void Draw();
	bool LoadFromConsole();

	//Compare by highscore
	bool operator<(const Player& other) const;

private:
	char name[MaxNameLength] = {};
	unsigned int highScore = 0;

};