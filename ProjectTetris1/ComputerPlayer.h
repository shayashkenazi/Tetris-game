#pragma once
#include "Player.h"
class ComputerPlayer : public Player
{
private:
	int level = easy;

public:
	ComputerPlayer(int _level) : Player(Computer_Player) , level(_level) {}

	char* CommandsString(Objects& obj);
	void Play(Objects** S);

};

