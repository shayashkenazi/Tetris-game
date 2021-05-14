#pragma once
#include "Player.h"
class ComputerPlayer : public Player
{
private:
	int level = easy;

public:
	ComputerPlayer(int _level,int player) : Player(player) , level(_level) {}
	int getPlayerLevel() override { return level; }

};

