#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_NAME_LENGTH 100

typedef struct name {
	char * str;
} name;

typedef struct arrayList	{
	name * arr;
	int size, cap;
} arrayList;

typedef struct fullList	{
	arrayList * aol;
	int size, cap;
} fullList;

arrayList * make_array_list (int);
int resize_arrayList (int, arrayList *); 
int add_to_end_arrayList (arrayList *, name);


int main ()	{
	int i, numOperations;
	char operation;
	name inputString1;
	name inputString2;
	inputString1.str = (char*)calloc(MAX_NAME_LENGTH + 1, sizeof(char));
	inputString2.str = (char*)calloc(MAX_NAME_LENGTH + 1, sizeof(char));
	
	// making arrayList	
	arrayList * al = make_array_list(1);
	if (al == NULL)	{
		return(1);
	}	
	scanf ("%d", &numOperations);
	for (i = 0; i < numOperations; i++)	{
		scanf (" %c", &operation);
		scanf (" %s", inputString1.str); 
		scanf (" %s", inputString2.str);
		if (operation == 'u')
	}	
		
	free(inputString1.str);
	free(inputString2.str);
	free (al->arr);
	free (al);
	
	return(0);
}

arrayList * make_array_list (int cap)	{
	arrayList * al;
	al = (arrayList *)calloc(1, sizeof(arrayList));
	al->arr  = (name *)calloc(cap, sizeof(name));
	al->size = 0;
	al->cap = cap;
	return al;
}

int resize_arrayList (int newCap, arrayList * al)	{
	name * tempArr = (name *)(realloc(al->arr, newCap * sizeof(name)));
	if (tempArr == NULL)	{
		printf ("failed to resize arrayList\n");
		return(1);
	}
	else	{
		al->arr = tempArr;
		al->cap = newCap;
	}
	return (0);
}

int add_to_end_arrayList (arrayList * al, name nm)	{
	if (al->size == al->cap)	{
		resize_arrayList (al->cap * 2, al);
	}	
	al->arr[al->size] = nm;
	al->size++;
	return (0);
}