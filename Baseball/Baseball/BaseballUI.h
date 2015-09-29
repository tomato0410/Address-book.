#include <stdio.h>
#include <stdlib.h>
#include "BaseballFunc.h"

#define SIZE 3

class BaseballUI
{
	public:
		BaseballUI();
		~BaseballUI();
		int requestMode();
		void setUserMode();
		void setAIMode();

	private:
		int quitMode;
};