#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 12

int numPermutations (int n);
int numBadPerms (char* givenWord, char** badWordList, int numBadWords);
int badPermHelper(char* givenWord, char** badWordList, int numBadWords, int* usedLetters, char* setLetters, int wordLength, int emptySpot);

int main ()	{

	// initializing the arays and getting inputs
	char * givenWord = calloc (MAX_WORD_LENGTH + 1, sizeof(char));
	scanf(" %12s", givenWord);
	int i, numBadWords, perms;
	scanf(" %d", &numBadWords);
	
	char** badWordList = calloc (numBadWords, sizeof(char*));
	if (badWordList == NULL)	{
		printf("Failed to allocate memeory for badWordList!\n");
		return 1;
	}
	
	// parsing bad words into badWordList
	for (i = 0; i < numBadWords; i++)	{
		badWordList[i] = calloc(MAX_WORD_LENGTH + 1, sizeof(char));
		if (badWordList[i] == NULL)	{
			printf("Failed to allocate memeory for badWordList!\n");
			return 1;
		}
		scanf(" %12s", badWordList[i]);
	}
	for (i = 0; i < numBadWords; i++){
		printf("%s\n", badWordList[i]);
	}
	
	perms = numBadPerms(givenWord, badWordList, numBadWords);
	printf("%d\n", perms);

	// freeing all the allocaion
	free(givenWord);
	for (i = 0; i < numBadWords; i++)	{
		free(badWordList[i]);
	}
	free(badWordList);
}

int numPermutations (int n)	{
	if (n == 1)	{
		return 1;
	}
	return n * numPermutations(n - 1);
}

int numBadPerms (char* givenWord, char** badWordList, int numBadWords)	{
	int* usedLetters = calloc(strlen(givenWord), sizeof(int));
	char* setLetters = calloc(strlen(givenWord), sizeof(char));
	int i, n;
	n = strlen(givenWord);
	for (i = 0; i < n; i++)	{
		usedLetters[i] = 0;
		setLetters[i] = '\0';
	}
	return badPermHelper(givenWord, badWordList,numBadWords, usedLetters, setLetters, n, 0);
	
}	

int badPermHelper(char* givenWord, char**badWordList, int numBadWords, int* usedLetters, char* setLetters, int wordLength, int emptySpot)	{
	int i, j, k, numBadPerms;
	int badWordLength;
	numBadPerms = 0;
	if (wordLength == emptySpot)	{
		return 1;
	}
	for (i = 0; i < wordLength; i++)	{
		if (usedLetters[i] == 0)	{
			usedLetters[i] = 1;
			setLetters[emptySpot] = givenWord[i];
			printf("%s\n", setLetters);
			
			badPermHelper(givenWord, badWordList, numBadWords, usedLetters, setLetters, wordLength, emptySpot + 1);
			
			usedLetters[i] = 0;
			setLetters[emptySpot] = '\0'; 
		}
	}
	
	return numBadPerms;
}