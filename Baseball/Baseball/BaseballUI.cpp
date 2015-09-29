#include "BaseballUI.h"

BaseballUI :: BaseballUI()
{
	printf("\n-------< Baseball Game >-------\n");
}

BaseballUI :: ~BaseballUI()
{
	printf("\n<Exit Baseball Game. Bye~>\n");
}

int BaseballUI :: requestMode()
{
	int ret;
	printf("\n(Select Mode!!)\n\n 1. User Mode\n 2. AI Mode\n 0. Exit\n\n");
	printf("\nSelect in Menu.\n");
	printf("Mode : ");
	scanf_s("%d", &ret);    
	fflush(stdin); 

	return ret;
}

 void BaseballUI :: setUserMode()
{
	BaseballFunc *baseballfunc = new BaseballFunc(SIZE);
	
	printf("\n-------< User Mode !! >-------\n");
	while(1)
	{
		if(baseballfunc->tryCount != 0)
		{
			baseballfunc->tryCount = 0;
		}
		baseballfunc->generateRandom();
		while(1)
		{
			baseballfunc->tryCount++;
			baseballfunc->inputNumber();
			if(baseballfunc->getResultBetweenRandomAndAnswer())
			{
				break;
			}
		}
		printf("\n After %d-times trying, You get a correct answer~!\n", baseballfunc->tryCount);
		printf("\n Do you want to play again? (1.Try again, 0.Quit user mode)\n");
		printf("Mode : ");
		scanf_s("%d", &quitMode);    
		fflush(stdin);
		if(quitMode == 0)
		{
			break;
		}
	}
	delete baseballfunc;
	baseballfunc = NULL;
}

void BaseballUI :: setAIMode()
{
	int i;
	BaseballFunc *baseballfunc = new BaseballFunc(SIZE);

	printf("\n-------< AI Mode !! >-------\n");
	while(1)
	{
		if(baseballfunc->tryCount != 0)
		{
			baseballfunc->tryCount = 0;
		}
		baseballfunc->generateRandom();

		printf("Guess Start: ");
		scanf_s("%d", &i);
		while(1)
		{
			baseballfunc->tryCount++;
			baseballfunc->guessNumber();
			if(baseballfunc->getResultBetweenRandomAndAnswer())
			{
				break;
			}
		}
		printf("\n After %d-times trying, Guessing Machine gets a correct answer~!\n", baseballfunc->tryCount);
		printf("\n Do you want to play again? (1.Try again, 0.Quit user mode)\n");
		printf("Mode : ");
		scanf_s("%d", &quitMode);    
		fflush(stdin);
		if(quitMode == 0)
		{
			break;
		}
	}

	delete baseballfunc;
	baseballfunc = NULL;
}