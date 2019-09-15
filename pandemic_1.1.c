#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct name {
	char * str; 
} name;

typedef struct arrayList	{
	name * arr;		// array of names
	int size, cap;
} arrayList;

typedef struct fullList	{
	arrayList * aol;	// array of lists(arrays)
	int size, cap;
} fullList;

#define MAX_WORD_LENGTH 100

arrayList * makeArrayList(int);
fullList * makeFullList(int);
void addToEndAl (arrayList *, name *);
void addToEndFl (fullList *, arrayList *);
void resizeAl (arrayList *, int);
void resizeFl (fullList *, int);

int main(void)	{

	
	// initiallizing and allocating the name structs
	name * person;
	name * symp;
	person = calloc(MAX_WORD_LENGTH + 1, sizeof(name));
	symp   = calloc(MAX_WORD_LENGTH + 1, sizeof(name));
	
	// defining the operation and number of operations variable
	char operation;
	int numOps;
	
	// defining temp arrays to store inputs
	char tempPerson[MAX_WORD_LENGTH + 1];
	char tempSymp[MAX_WORD_LENGTH + 1];
	
	// getting input for numOps
	scanf("%d", &numOps);
		
	for (int i = 0; i < numOps; i++)	{
		// getting inputs for each op
		scanf(" %c", &operation);
		scanf(" %s", tempPerson);
		scanf(" %s", tempSymp);
		if (operation == 'u')	{
			
				
		}

		
	}
	
	
	free (person);
	free (symp);
}

arrayList * makeArrayList(int cap)	{
	arrayList * ret;
	ret = calloc(1, sizeof(arrayList));
	if (ret == NULL)	{
		printf("Failed to make arrayList\n");
		return NULL;
	}
	ret->arr  = calloc(cap, sizeof(name));
	if (ret->arr == NULL)	{
		printf("Failed to make arrayList\n");
		return NULL;
	}	
	ret->cap  = cap;
	ret->size = 0;
	return ret;
}
fullList * makeFullList(int cap)	{
	fullList * ret;
	ret = calloc(1, sizeof(fullList));
	if (ret == NULL)	{
		printf("Failed to make fullList\n");
		return NULL;
	}	
	ret->aol  = calloc(cap, sizeof(arrayList));
	if (ret->aol == NULL)	{	
		printf("Failed to make fullList->aol\n");	
		return NULL;
	}
	ret->cap = cap;
	ret->size = 0;
	return ret;
}
int resizeAl (arrayList * al, int newCap)	{
	arrayList * newArrList;
	newArrList = realloc(al, newCap*(sizeof(arrayList));
	if (newArraylist == NULL)	
		printf("Failed to reallocate arrayList\n");
			return (1);
	
	return(0);
}

int resizeFl (fullList *, int newCap)

int addToEndAl (arrayList * al, name * nm)	{
	if (al->size == al->cap)	
		resizeAl(al, (al->cap)*2);
	al->arr[al->size] = nm;
	al->size++;
}

void addToEndFl (fullList * fl, arrayList * al)

