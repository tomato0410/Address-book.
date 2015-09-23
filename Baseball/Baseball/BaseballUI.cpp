#include <stdio.h>
#include "BaseballUI.h"

BaseballUI :: BaseballUI()
{
	printf("\n-------< Baseball Game >-------\n");
	printf("\n(Select Mode!!)\n\n 1. User Mode\n 2. AI Mode\n 0. Exit\n\n");
}

BaseballUI :: ~BaseballUI()
{
	printf("\n<Exit Baseball Game. Bye~>\n");
}

int BaseballUI :: requestMode()
{
	int ret;
	printf("\nSelect in Menu.\n");
	printf("Mode : ");
	scanf_s("%d", &ret);    
	fflush(stdin); 

	return ret;
}

 void BaseballUI :: setUserMode()
{
	printf("\n-------< User Mode !! >-------\n");
}

void BaseballUI :: setAIMode()
{
	printf("\n-------< AI Mode !! >-------\n");
}