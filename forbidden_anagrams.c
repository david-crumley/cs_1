#include <stdlib.h>
#include <stdio.h>

#define MAX_WORD_LENGTH 12


int main ()	{

	// initializing the arays and getting inputs
	char * givenWord = calloc (MAX_WORD_LENGTH + 1, sizeof(char));
	scanf(" %12s", givenWord);
	int i, numBadWords;
	scanf(" %d", &numBadWords);
	
	char** badWordList = calloc (numBadWords, sizeof(char*));
	if (badWordList == NULL)	{
		printf("Failed to allocate memeory for badWordList!\n");
		return 1;
	}
	for (i = 0; i < numBadWords; i++)	{
		badWordList[i] = calloc(MAX_WORD_LENGTH + 1, sizeof(char));
		if (badWordList[i] == NULL)	{
			printf("Failed to allocate memeory for badWordList!\n");
			return 1;
		}
		scanf(" %12s", badWordList[i]);
		
	}


	// freeing all the allocaion
	free(givenWord);
	for (i = 0; i < numBadWords; i++)	{
		free(badWordList[i]);
	}
	free(badWordList);

	
}


}