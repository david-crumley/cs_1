#include <stdio.h>
#include <stdlib.h>			/*************************///    Current Progress  //*******************************
#include <string.h>			// All functions tested and working properly							 			/
							//	  fix this shit (use print statements in the loops to make sure they work		/
#define	MAX_NAME_LENGTH 100 //														  							/
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

#define STARTING_CAP 1

int main ()	{
	int i, j, k, numOperations, flag;
	char operation;
	name inputString1;
	name inputString2;
		
	
	fullList * symptom = make_fullList(STARTING_CAP);
	if (symptom == NULL)	{
		return(1);
	}
	fullList * student = make_fullList(STARTING_CAP);
	if (student == NULL)	{
		return(1);
	}
	scanf ("%d", &numOperations);
	for (i = 0; i < numOperations; i++)	{
		
		inputString1.str = (char*)calloc(MAX_NAME_LENGTH + 1, sizeof(char));
		inputString2.str = (char*)calloc(MAX_NAME_LENGTH + 1, sizeof(char));
		
		scanf (" %c", &operation);
		scanf (" %s", inputString1.str); 
		scanf (" %s", inputString2.str);
		
		flag = 1;
		
		if (operation == 'u')	{
			flag = 0;
			
			// check symptom->aol[j].arr[0].str for a match with inputString2
			for (j = 0; j < symptom->size; j++)	{
				
				if (strcmp (symptom->aol[j].arr[0].str, inputString2.str) == 0)	{	//This means there is a match
					
					for (k = 0; k < symptom->aol[j].size; k++)	{
						if (strcmp (symptom->aol[j].arr[k].str, inputString1.str) == 0)	{
							flag = -1;
						}
					}
					if (flag > -1)	{
						add_to_end_arrayList (&symptom->aol[j], inputString1);			// adding the name of the student at the end of the list
						flag = 1;
					}
					
					
					
				}
			}
			// if no matches (flag is 0)
			if (flag == 0)	{
				printf("test\n");
				arrayList * newArrList = make_array_list(STARTING_CAP);
				add_to_end_arrayList(newArrList, inputString2);
				add_to_end_arrayList(newArrList, inputString1);
				add_to_end_fullList(symptom, newArrList);
				free (newArrList);
				printf ("%s\n", symptom->aol[0].arr[0].str);
				printf ("size: %d; cap: %d\n", symptom->aol[0].size, symptom->aol[0].cap);
				

				
			}
			
		
			// chack student->aol[j].arr[0].str for a match with inputString1
			for (j = 0; j < student->size; j++)	{
				if (strcmp (student->aol[j].arr[0].str, inputString1.str) == 0)	{
					for (k = 0; k < student->aol[j].size; k++)	{
						if (strcmp (student->aol[j].arr[k].str, inputString2.str) == 0)	{
							flag = -1;
						}
					}
					if (flag > -1)	{
						add_to_end_arrayList (&student->aol[j], inputString2);
						flag = 1;
					}
					
					
				}
			}
			if (flag == 0)	{
				printf("test\n");
				arrayList * newArrList = make_array_list(STARTING_CAP);
				add_to_end_arrayList(newArrList, inputString1);
				add_to_end_arrayList(newArrList, inputString2);
				add_to_end_fullList(student, newArrList);
				printf ("%s\n", student->aol[0].arr[0].str);
				free (newArrList);
				
			}
		}
		
		else if (operation == 'q')	{
			
			// check if inputString1 is "symptom" or "student"
			if (strcmp (inputString1.str, "symptom") == 0)	{
				
				for (j = 0; j < symptom->size; j++)	{
					printf ("test\n");
					printf("%s", symptom->aol[j].arr[0].str);
					if (strcmp (symptom->aol[j].arr[0].str, inputString2.str) == 0)	{
						printf ("test\n");
						printf("%d\n", symptom->aol[j].size - 1);	
						for (k = 0; k < symptom->aol[j].size - 1; k++)	{
							printf ("test\n");
							printf("%s\n", symptom->aol[j].arr[k + 1].str);
						}
					}
				}								
			}
			
			else if (strcmp (inputString1.str, "student")== 0)	{
				for (j = 0; j < student->size; j++)	{
					if (strcmp (student->aol[j].arr[0].str, inputString2.str) == 0)	{
						printf("%d\n", student->aol[j].size);
						for (k = 0; k < student->aol[j].size; k++)	{
							printf("%s\n", student->aol[j].arr[k].str);
						}
					}
				}
			}
		
		
		
		}
		free(inputString1.str);
		free(inputString2.str);

	}			
		
	
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
	fl->size++;
	return (0);
}