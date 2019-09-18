#include <stdio.h>
#include <stdlib.h>			/*************************///    Current Progress  //*******************************
#include <string.h>			// All functions tested and working properly							 			/
							//	  Finish the search through the student fullList       							/
#define	MAX_NAME_LENGTH 100 //		for inputString1															/
							/***********************************************************************************/
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
fullList * make_fullList (int);

int resize_arrayList (int, arrayList *); 
int resize_fullList(int, fullList *);

int add_to_end_arrayList (arrayList *, name);
int add_to_end_fullList (fullList *, arrayList *);

int main ()	{
	int i, j, numOperations, flag;
	char operation;
	name inputString1;
	name inputString2;
	inputString1.str = (char*)calloc(MAX_NAME_LENGTH + 1, sizeof(char));
	inputString2.str = (char*)calloc(MAX_NAME_LENGTH + 1, sizeof(char));
	
	/****  Dont need to do this yet *****
	
	arrayList * al = make_array_list(1);
	if (al == NULL) {
		return(1);
	}
	*/
	
	fullList * symptom = make_fullList(1);
	if (symptom == NULL)	{
		return(1);
	}
	fullList * student = make_fullList(1);
	if (student == NULL)	{
		return(1);
	}
	scanf ("%d", &numOperations);
	for (i = 0; i < numOperations; i++)	{
		scanf (" %c", &operation);
		scanf (" %s", inputString1.str); 
		scanf (" %s", inputString2.str);
	flag = 0;
		
		if (operation == 'u')	{
			// check symptom->aol[j].arr[0].str for a match with inputString2
			for (j = 0; j < symptom->size; j++)	{
				if (strcmp (symptom->aol[j].arr[0].str, inputString2.str) == 0)	{	//This means there is a match
					add_to_end_arrayList (&symptom->aol[j], inputString1);			// adding the name of the student at the end of the list
					
					flag = 1;
				}
			}
			// if no matches (flag is 0)
			if (flag == 0)	{
				arrayList * newArrList = make_array_list(1);
				add_to_end_arrayList(newArrList, inputString1);
				add_to_end_fullList(symptom, newArrList);
				
			}
		
			// chack student->aol[j].arr[0].str for a match with inputString1
			for (j = 0; j < student->size; j++)
		
	
	
	
	}	
			
		
	free(inputString1.str);
	free(inputString2.str);
	free (symptom->aol);
	free (symptom);
	free (student->aol);
	free (student);
	
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
	name * tempArr = (name *)realloc(al->arr, newCap * sizeof(name));
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

fullList * make_fullList (int cap)	{
	fullList * fl;
	fl = (fullList *)calloc(1, sizeof(fullList));
	fl->aol = (arrayList *)calloc(cap, sizeof(arrayList));
	fl->size = 0;
	fl->cap = cap;
	return fl;
}

int resize_fullList (int newCap, fullList * fl)	{
	arrayList * tempAol = (arrayList *)realloc(fl->aol, newCap * sizeof(arrayList));
	if (tempAol == NULL)	{
		printf("Failed to resize fullList\n");
		return (1);
	}
	else {
		fl->aol = tempAol;
		fl->cap = newCap;
	}
	return (0);
}

int add_to_end_fullList (fullList * fl, arrayList * al)	{
	if (fl->size == fl->cap)	{
		resize_fullList (fl->cap * 2, fl);
	}
	fl->aol[fl->size] = *al;
	al->size++;
	return (0);
}