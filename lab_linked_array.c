#include <stdio.h>
#include <stdlib.h>

typedef struct arrayPiece arrayPiece;

typedef struct arrayPiece	{
	char* name;
	arrayPiece* likes;
	arrayPiece* dislikes;
} arrayPiece;

int main ()	{
	
	int i;

	arrayPiece* * arrayPiecePtrs = calloc (3, sizeof(arrayPiece*));
	arrayPiecePtrs[0] = calloc (1, sizeof(arrayPiece));
	arrayPiecePtrs[1] = calloc (1, sizeof(arrayPiece));
	arrayPiecePtrs[2] = calloc (1, sizeof(arrayPiece));

	arrayPiecePtrs[0]->name = "Greg";
	arrayPiecePtrs[1]->name = "Steve";
	arrayPiecePtrs[2]->name = "Matt";

	// for greg
	arrayPiecePtrs[0]->likes = NULL;
	arrayPiecePtrs[0]->dislikes = NULL;

	// for steve
	arrayPiecePtrs[1]->likes = arrayPiecePtrs[2];   // likes matt
	arrayPiecePtrs[1]->dislikes = NULL;

	// for matt
	arrayPiecePtrs[2]->likes = arrayPiecePtrs[0];	// likes greg
	arrayPiecePtrs[2]->dislikes = NULL;

	// print everyone
	for (i = 0; i < 3; i++)	{
		printf("%s\n", arrayPiecePtrs[i]->name);
		if (arrayPiecePtrs[i]->likes != NULL)	{
			printf("Likes: %s\n", arrayPiecePtrs[i]->likes->name);
		}
		if (arrayPiecePtrs[i]->dislikes != NULL)	{
			printf("Dislikes: %s\n", arrayPiecePtrs[i]->likes->name);
		}
		printf("\n");
	}
	
	
	// changing gregs dislike to steve from steve
	arrayPiecePtrs[1]->likes->likes->dislikes = arrayPiecePtrs[1];

	// print everyone
	for (i = 0; i < 3; i++)	{
		printf("%s\n", arrayPiecePtrs[i]->name);
		if (arrayPiecePtrs[i]->likes != NULL)	{
			printf("Likes: %s\n", arrayPiecePtrs[i]->likes->name);
		}
		if (arrayPiecePtrs[i]->dislikes != NULL)	{
			printf("Dislikes: %s\n", arrayPiecePtrs[i]->dislikes->name);
		}
		printf("\n");
	}

	// keeping track of every one that likes steve
	printf("People who like steve:\n");
	for (i = 0; i < 3; i++)	{
		if (arrayPiecePtrs[i]->likes == arrayPiecePtrs[1])	{
			printf("%s\n", arrayPiecePtrs[i]->name);
		}
	}
		



}