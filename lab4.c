/*
 * CSC101 Lab 4
 * By: Charlie Melbye
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "checkit.h"

#include "lab4.h"

int main(void)
{
	char characterToEncode = 0;
	
	int lowerSumBound = 0;
	int upperSumBound = 0;
	int finalSum = 0;

	srand((unsigned int) time(0));

	test_cases();

	while(1) {
		printf("Enter a character: ");
		scanf("%c", &characterToEncode);
		getchar();

		if (characterToEncode == 48)
		{
			break;
		}

		printf("Encoded in rot13, '%c' is '%c' (%d).\n\n",
			characterToEncode,
			convertToRot13(characterToEncode),
			convertToRot13(characterToEncode));
	}

	printf("\n");

	printf("Enter two numbers to find the sum of all numbers between them.\n");

	printf("First number: ");
	scanf("%d", &lowerSumBound);
	getchar();

	printf("Second number: ");
	scanf("%d", &upperSumBound);
	getchar();

	finalSum = sumValuesInRange(lowerSumBound, upperSumBound);

	printf("The sum of numbers between %d and %d is %d\n\n", lowerSumBound, upperSumBound, finalSum);

	randomNumberGame();

	return 0;
}

char convertToRot13(char originalCharacter)
{
	char encodedCharacter = 0;

	if (!isalpha(originalCharacter))
	{
		return originalCharacter;
	}

	if (isupper(originalCharacter) && ((originalCharacter + 13) > 90))
	{
		encodedCharacter = 64 + ((originalCharacter + 13) - 90);
	}
	else if ((originalCharacter + 13) > 122) {
		encodedCharacter = 96 + ((originalCharacter + 13) - 122);
	}
	else
	{
		encodedCharacter = originalCharacter + 13;
	}

	return encodedCharacter;
}

int sumValuesInRange(int beginning, int end)
{
	int sum = 0;

	for(;beginning <= end;beginning++)
	{
		sum += beginning;
	}

	return sum;
}

void randomNumberGame(void)
{
	int numberToGuess = 0;
	int currentGuess = 0;

	numberToGuess = (rand() % 10) + 1;

	printf("I'm thinking of a number...\n");

	while(1) {
		printf("What's your guess? ");
		scanf("%d", &currentGuess);
		getchar();

		if(currentGuess > numberToGuess)
		{
			printf("Your guess was too high.\n\n");
		}
		else if(currentGuess < numberToGuess)
		{
			printf("Your guess was too low.\n\n");
		}
		else
		{
			break;
		}
	}

	printf("Your guess was right!\n");
}

void test_cases(void)
{
	/* Test convertToRot13() */
	checkit_char(convertToRot13('e'), 'r');
	checkit_char(convertToRot13('v'), 'i');

	checkit_char(convertToRot13('M'), 'Z');
	checkit_char(convertToRot13('T'), 'G');

	/* Test sumValuesInRange() */
	checkit_int(sumValuesInRange(2, 5), 14);
	checkit_int(sumValuesInRange(2, 2), 2);
	checkit_int(sumValuesInRange(-5, 6), 6);

	/* Test randomNumberGame() */
	/* ??? */
}
