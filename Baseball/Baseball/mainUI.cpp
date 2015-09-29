#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BaseballUI.h"

#define USER_MODE 1
#define AI_MODE   2
#define QUIT     0

int main(void)
{
	int gameMode;
	BaseballUI *baseballui = new BaseballUI;
	
	while(1)
	{
		gameMode = baseballui->requestMode();
		if(gameMode == 1)
		{
			baseballui->setUserMode();
		}
		else if(gameMode == 2)
		{
			baseballui->setAIMode();
		}
		else if(gameMode == 0)
		{
			break;
		}
	}
	delete baseballui;
	baseballui = NULL;
}