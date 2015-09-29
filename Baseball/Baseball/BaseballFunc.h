#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define REDUNDANCY 0
#define EXCLUSIVENESS 1

#define RANDOM_SOCCESS 0
#define RANDOM_FAIL 1

#define NOTOUT 0
#define OUT 1

#define TABLE_INIT_FAIL 0
#define TABLE_INIT_SUCCESS 1

#define TABLE_RELEASE_FAIL 0
#define TABLE_RELEASE_SUCCESS 1

typedef struct table{
	int number[3];
	bool index;
}TABLE;

class BaseballFunc
{
	public:
		int tryCount;
		BaseballFunc(int size);
		~BaseballFunc();
		void generateRandom();
		void generateAnswer();
		void guessNumber();
		void inputNumber();
		int getResultBetweenRandomAndAnswer();

	private:
		int arraySize;
		int *random;
		int *answer;
		int *result;
		TABLE *table;
		int checkRedundancy(int *number);
		int generateNumber(int *number);
		void getResult(int *number1, int *number2);
		int initTable();
		int releaseTable();
};