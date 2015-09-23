#include <stdio.h>
#include "BaseballUI.h"

int main(void)
{
	int mode; 
	BaseballUI *baseballui = new BaseballUI;
	
	while(1)
	{
		mode = baseballui->requestMode();
		if(mode == 1)
		{
			baseballui->setUserMode();
		}
		else if(mode == 2)
		{
			baseballui->setAIMode();
		}
		else if(mode == 0)
		{
			break;
		}
	}
	delete baseballui;
	baseballui = NULL;
}