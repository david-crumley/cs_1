#include <stdio.h>
#include <stdlib.h>

typedef struct arrayPiece arrayPiece;

typedef struct arrayPiece	{
	int value;
	arrayPiece* nextPiece;
} arrayPiece;

arrayPiece* append (arrayPiece* tailPiece, int value);
arrayPiece* prepend (arrayPiece* headPiece, int value);
arrayPiece* deleteByIndex (arrayPiece* headPiece, int index);
void printArray (arrayPiece* headPiece);
void freeArray (arrayPiece* headPiece);
	
int main ()	{
	
	
	arrayPiece* headPiece = calloc(1, sizeof(arrayPiece));
	headPiece->value = 5;
	headPiece->nextPiece = NULL;
	arrayPiece* tailPiece = headPiece;
	
	tailPiece = append (tailPiece, 6);
	tailPiece = append (tailPiece, 7);
	
	headPiece = prepend (headPiece, 4);
	headPiece = prepend (headPiece, 3);
	
	tailPiece = append (tailPiece, 8);
	headPiece = prepend (headPiece, 2);
	headPiece = prepend (headPiece, 1);
	
	printArray (headPiece);

	headPiece = deleteByIndex(headPiece, 3);
	
	printArray (headPiece);

	freeArray (headPiece);
	
return (0);
	
}

arrayPiece* append (arrayPiece* tailPiece, int value)	{
	
	arrayPiece* newTail = calloc(1, sizeof(arrayPiece));
	if (newTail == NULL)	{
		return NULL;
	}
	newTail->value = value;
	newTail->nextPiece = NULL;
	
	tailPiece->nextPiece = newTail;
	
	return newTail;
}
	
void printArray (arrayPiece* headPiece)	{
	
	while (headPiece != NULL)	{
		printf("%d\n", headPiece->value);
		headPiece = headPiece->nextPiece;
	}
}

arrayPiece* prepend (arrayPiece* headPiece, int value)	{
	
	arrayPiece* newHead = calloc(1, sizeof(arrayPiece));
	if (newHead == NULL)	{
		return NULL;
	}
	newHead->value = value;
	newHead->nextPiece = headPiece;
	return newHead;
}

void freeArray(arrayPiece* headPiece)	{
	
	while (headPiece != NULL)	{
		arrayPiece* secondArrayPiece = headPiece->nextPiece; 
		free(headPiece);
		headPiece = secondArrayPiece;
		
	}
}
		
arrayPiece* deleteByIndex (arrayPiece* headPiece, int index)	{
	
	arrayPiece* somePiece = headPiece;
	if (somePiece == NULL)	{
		return somePiece;
	}
	if (index == 0)	{
		arrayPiece* replacementPiece = somePiece->nextPiece;
		somePice = 
		free (somePiece);
		
		
	}
	
	somePiece = deleteByIndex (somePiece->nextPiece, index - 1);
	
}



