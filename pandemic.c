#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct name	{
	char * str[MAX_NAME_LENGTH + 1]; 	// just a string
} name;

typedef struct arrayList	{
	name * arr;     // array of namespace
	int size, cap;
} arrayList;

typedef struct fullList	{
	arrayList * aol;	// array of (array) lists
	int size, cap;
} fullList;

fullList * makeFullList (int );
arrayList * makeArrayList (int );
void resizeFl (fullList * fl, int newCap);
void resizeAl (arrayList * al, int newCap);
void addToEndFl (fullList * fl, arrayList * al);
void addToEndAl (arrayList * al, name * nm);
void parseInput (char str[]);

int main()	{
	
	/* testing: creating fullList and printing it out 
	
	fullList * grid  = makeFullList (1);
	arrayList * list = makeArrayList(1);
		
	name name1;
	sprintf(*name1.str, "hello");
	
	addToEndAl(list, &name1);
	addToEndFl(grid, list);

	printf("%s ", *name1.str);				// printing from name struct
	printf("%s ", *list->arr[0].str);		// printing from arrayList struct
	printf("%s ", *grid->aol->arr[0].str);	// printing from fullList struct

	
	printf ("\n");
	
	free(list);
	free(grid);
	
	*/
	
	int numOps, i, j, k;
	int flag = 0;
	char operation[2];
	name * person;
	name * symp;

	// initialize the structs
	fullList * sympTable = makeFullList(1);
	fullList * nameTable = makeFullList(1);
	arrayList * sympList = makeArrayList(1);
	arrayList * nameList = makeArrayList(1);
	scanf("%d", &numOps);
	
	// alloating the 'name' structs
	person = calloc(MAX_NAME_LENGTH + 1, sizeof(char));
	symp   = calloc(MAX_NAME_LENGTH + 1, sizeof(char));
	
	// building the symp Table
	addToEndAl(sympList, symp);
	addToEndFl(sympTable, sympList);
	
	// building the name table
	addToEndAl(nameList, person);
	addToEndFl(nameTable, nameList);
	
	for (i = 0; i < numOps; i++)	{
		scanf (" %s", operation);
		scanf (" %s", *person->str);
		scanf (" %s", *symp->str);
		if (operation[0] == 'u')	{
			printf("op = u\n");
						
			// sympTable loop
			for (j = 0; j < (sympTable->size); j++)	{
				printf("I'm loopin!\n");
			
				// if there exists a list starting with the sympton that was input
				for (k = 0; k < strlen(*sympTable->aol[j].arr[0].str); k++) 	{
					printf("Found a match!\n");
					
					
					addToEndAl(sympList, person);
					printf("%s\n", *sympTable->aol[j].arr[sympTable->aol[j].size].str);
					flag = 1;
				}
			}
					
			// if the symptom is not recognized
			if	(flag < 1)	{
				printf("New symptom!\n");
				addToEndAl (sympList, symp);
				addToEndFl(sympTable, sympList);
				printf("%s\n", *sympTable->aol[sympTable->size].arr[0].str);
				
			}
			flag = 0;
			
		}
		
	}
	
	free (sympTable);
	free (nameTable);
	free (sympList);
	free (nameList);
		
	return(0);
}
	
fullList * makeFullList(int cap)	{
	fullList * temp;
	temp       = calloc(1, sizeof(fullList));
	temp->aol  = calloc(cap, sizeof(arrayList));
	temp->cap  = cap;
	temp->size = 0;
	return temp;
}

arrayList * makeArrayList(int cap)	{
	arrayList * temp;
	temp       = calloc(1, sizeof(arrayList));
	temp->arr  = calloc(cap, sizeof(name));
	temp->cap  = cap;
	temp->size = 0;
	return temp;
}	
void resizeFl (fullList * fl, int newCap)	{
	fl->aol = realloc(fl->aol, newCap*sizeof(arrayList));
	fl->cap = newCap;
}
void resizeAl (arrayList * al, int newCap)	{
	al->arr = realloc(al->arr, newCap*sizeof(name));
	al->cap = newCap;
}	
void addToEndFl (fullList * fl, arrayList * al)	{
	if (fl->size == fl->cap)	{
		resizeFl (fl, (fl->cap)*2);
	}
	fl->aol[fl->size] = *al;
	fl->size++;
}

void addToEndAl (arrayList * al, name * nm)	{
	if (al->size == al->cap)	{
		resizeAl (al, (al->cap)*2);
	}
	al->arr[al->size] = *nm;
	al->size++;
}
