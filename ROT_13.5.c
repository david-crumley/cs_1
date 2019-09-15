#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 100
#define NOT_VOWEL  13
#define VOWEL      14

void encryptInit(char*);
int wrapper (int);

int main ()	{
	
	int numLines;
	char word[WORD_SIZE + 1];
	scanf("%d", &numLines);
	printf("\n");
	for (int i=0; i < numLines; i++)	{
		scanf ("%s", word);
		encryptInit(word);
		printf ("%s\n\n", word);
	}
	
	return(0);
}

int wrapper (int num)	{
	
	int diff;
	int new;
	if (num>122)	{
		diff = num - 122;
		new = (97 + diff) - 1;
		return(new);
	}
	else 
		return (num);
}	

void encryptInit(char* word)	{

	char str[WORD_SIZE];
	int temp;
	int diff;
	
	// create copy of original word
	for (int j=0; j<strlen(word); j++)	{
		str[j] = word[j];
	}
	
	// check first letter
	temp = str[0] + NOT_VOWEL;
	word[0] = wrapper(temp);
	
	// start loop at second letter and backcheck the previos letter each time for vowel
	for (int i=1; i<strlen(word); i++)		{
		
		if (str[i-1]=='a'||str[i-1]=='e'||str[i-1]=='i'||str[i-1]=='o'||str[i-1]=='u')	{
			temp = str[i] + VOWEL;
			temp = wrapper(temp);
		}
		else	{ 
			temp = str[i] + NOT_VOWEL;
			temp = wrapper(temp);	
		}
		word[i] = temp;
	
	}
}	