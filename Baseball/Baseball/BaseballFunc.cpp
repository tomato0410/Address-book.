#include "BaseballFunc.h"

BaseballFunc :: BaseballFunc(int size)
{
	arraySize = size;
	tryCount = 0;
	random = new int[arraySize];
	answer = new int[arraySize];
	result = new int[2];

	memset(random, 0, arraySize*sizeof(int));
	memset(answer, 0, arraySize*sizeof(int));
	memset(result, 0, 2*sizeof(int));

	table = NULL;
}

BaseballFunc :: ~BaseballFunc()
{
	if(random)
	{
		delete[] random; random = NULL;
	}
	if(answer)
	{
		delete[] answer; answer = NULL;
	}
	if(result)
	{
		delete[] result; result = NULL;
	}
}

void BaseballFunc :: generateRandom()
{
	int ret;
	ret = generateNumber(random);
}
void BaseballFunc :: generateAnswer()
{
	int ret;
	ret = generateNumber(answer);
}

void BaseballFunc :: guessNumber()	// Number Guessing Algorithm
{
	int i, start, tableSize;
	int prevResult[2] = {0,};
	
	printf("\n( Guess Number )\n");
	printf("Start! "); scanf_s("%d", &start); fflush(stdin);

	memcpy(prevResult, result, 2*sizeof(int));

	if(!table)
	{
		initTable();
	}
	tableSize = (int)(pow((float)10, (float)arraySize));

	if(tryCount == 1)
	{
		generateAnswer();
	}
	else
	{
		for(i = 0 ; i < tableSize ; i++)
		{
			if(table[i].index)
			{
				getResult(answer, table[i].number);
				if(memcmp(prevResult, result, 2*sizeof(int)))
				{
					table[i].index = false;
				}
			}
		}

		for(i = 0 ; i < tableSize ; i++)
		{
			if(table[i].index)
			{
				memcpy(answer, table[i].number, arraySize*sizeof(int));
				break;
			}
		}

		printf("Number : ");
		for(i = 0 ; i < arraySize ; i++)
		{
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}

void BaseballFunc :: inputNumber()
{
	int i;
	while(1)
	{
		printf("\n( Input Number )\n");
		for(i = 0 ; i < arraySize ; i++)
		{
			printf("input %d number : ", i+1);
			scanf_s("%d", &answer[i], sizeof(int));
		}

		if(checkRedundancy(answer) == REDUNDANCY)
		{
			printf("\nPlease Input Number Exclusively\n");
		}
		else
		{
			break;
		}
	}
	/*
	printf("\nInput data : \n");
	for(i = 0 ; i < size ; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	*/
}

int BaseballFunc :: getResultBetweenRandomAndAnswer()
{
	int ret;
	getResult(random, answer);
	printf("\nThe Result is %d Strike, %d Ball~!\n", result[0], result[1]);
	if(result[0] == 3)
	{
		printf("\n3 Strike Out~!\n");
		if(table)
		{
			releaseTable();
		}
		ret = OUT;
	}
	else
	{
		ret = NOTOUT;
	}
	return ret;
}

int BaseballFunc :: checkRedundancy(int *number)
{
	int i, j;
	for(i = 0 ; i < arraySize-1 ; i++)
	{
		for(j = i+1 ; j < arraySize ; j++)
		{
			if(number[i] == number[j])
			{
				return REDUNDANCY;
			}
		}
	}
	return EXCLUSIVENESS;
}

int BaseballFunc :: generateNumber(int *number)
{
	int i, j, ret;
	srand((unsigned)time(NULL));
	number[0] = rand() % 10;
	for(i = 1 ; i < arraySize ; i++)
	{
		number[i] = rand() % 10;
		j = 0;
		while(j < i)
		{
			if(number[i] == number[j])
			{
				number[i] = rand() % 10;
				j = 0;
			}
			else
			{
				j++;
			}
		}
	}

	printf("Number : ");
	for(i = 0 ; i < arraySize ; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");

	ret = number ? RANDOM_SOCCESS : RANDOM_FAIL;
	return ret;
}

void BaseballFunc :: getResult(int *number1, int *number2)
{
	int i, j;
	result[0] = result[1] = 0;
	for(i = 0 ; i < arraySize ; i++)
	{
		for(j = 0 ; j < arraySize ; j++)
		{
			if(number1[i] == number2[j])
			{
				if(i == j)
				{
					result[0]++; // Strike
				}
				else
				{
					result[1]++; // Ball
				}
			}
		}
	}
}

int BaseballFunc :: initTable()
{
	int i, ret, tableSize;

	tableSize = (int)(pow((float)10, (float)arraySize));
	table = new TABLE[tableSize];
	
	for(i = 0 ; i < tableSize ; i++)
	{
		table[i].number[0] = (int)(i/100);
		table[i].number[1] = (int)((i - (table[i].number[0] * 100)) / 10);
		table[i].number[2] = i % 10;

		table[i].index = (checkRedundancy(table[i].number) == REDUNDANCY) ? false : true;
	}
	/*
	for(i = 0 ; i < tableSize ; i++)
	{
		printf("%d, %d, %d, %d\n", table[i].number[0], table[i].number[1], table[i].number[2], table[i].index);
	}
	printf("\n");
	*/
	ret = table ? TABLE_INIT_SUCCESS : TABLE_INIT_FAIL;
	return ret;
}

int BaseballFunc :: releaseTable()
{
	int ret;
	if(table)
	{
		delete[] table; table = NULL;
	}
	ret = table ? TABLE_RELEASE_FAIL : TABLE_RELEASE_SUCCESS;
	return ret;
}