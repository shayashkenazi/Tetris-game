#include "ComputerPlayer.h"



char* ComputerPlayer:: CommandsString(Objects& obj)
{
	char* commands = obj.FindBestSpot(boardGameForPlayer,easy, playerNumber);
	return commands;
}

void ComputerPlayer::Play(Objects** S)
{
	char* commands = CommandsString(**S);
	char key;
	for (int i = 0; i < CommandLoop; i++)
	{
		key = commands[i];
		
		
		
		Sleep(50);
	}
}
