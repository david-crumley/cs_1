#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name	{
	char * str;			// this is for the individual strings
} name;					

typedef struct arrayList	{
	name * arr;			// a pointer to a list of names starting with a symptom or symptoms starting with a name
	int size;			// starts at zero 
	int cap;			// amount of memory allocated
} arrayList;

typedef struct fullList	{
	arrayList * aol;		// a pointer to an array of pointers that point at pointers of strings LOL 
	int size;
	int cap;
} fullList;

/*  psuedo code *
 ****************
 * take integer input for number of operations
 * for (num of ops)...
 *	take input (char, str1, str2)
 *	if (char == u)...
 *	  if (look for an arrayList with str1 (name) at [0] in the student fullList 	  
 *	  	add str2(symptom) to the end of this arrayList
 *    if (look for an arryist with str2(symptom) at [0] in the symptom fullList
 *      add str1(name) to the end of this arrayList
 *    else
 *      put an arrayList in the student fullList
 *      put str1(name of student) in [0] of the new arrayList
 *      put str2(symptom) at the end
 *      put an arryList in the symptom fullList
 *      put str2 (symptom) in [0] of the new arrayList
 *      put str1 at the end
 *	else if (char == q)
 *    if (str1 == 'symptom')
 *      look for arrayList [0] that == str2 in symptom fullList
 *      print number of students with symptom
 *      print all strings in this arrayList after [0] on a seperate line
 *    else if (str1 == 'student')
 *      look for arrayList [0] that == str2 in student fullList
 *      print number of symptoms the student has
 *      print all the symptoms for that student	 
 */
 
int main()	{
	
	int numOps, i, j;
	char op;
	char tempStr1[101];
	char tempStr2[101];
	name * str1 = calloc(1, sizeof(name));
	
	if (str1 == NULL)	{
		printf("str1 failed to allocate\n");
		return(1);
	}
	name * str2 = calloc(1, sizeof(name));
	
	if (str2 == NULL)	{
		printf("str2 failed to allocate\n");
		return(1);
	}
	// will be changed to a function
	fullList * student = calloc(1, sizeof(fullList));
	
	if (student == NULL)	{
		printf("student failed to allocate\n");
		return(1);
	}
	student->size = 0;
	student->cap  = 1;
	
	// will be changed to a funvtion
	fullList * symptom = calloc(1, sizeof(fullList));
	
	if (symptom == NULL)	{
		printf("symptom failed to allocate\n");
		return(1);
	}
	symptom->size = 0;
	symptom->cap  = 1;
	
	scanf("%d", &numOps);
	
	for (i = 0; i < numOps; i++)	{
		scanf(" %c", &op);
		scanf(" %s", tempStr1);
		scanf(" %s", tempStr2);
		str1->str = tempStr1;
		str2->str = tempStr2;
		
		if (op == 'u')	{
			if (student->size > 0)	{
				for (j = 0; j < student->size; j++)	{
					
		// If theres a match in the student list do this vvv
					
					if (strcmp(student->aol[j].arr[0].str, str1->str) == 0)	{
						// will make a add to end function for this
						if (student->aol[j].size == student->aol[j].cap)	{
							// resize func
							arrayList * ar = realloc(student->aol[j].arr, (student->aol[j].cap * 2) *sizeof(name));
							
							if (ar == NULL)	{
								printf("realloc fail\n");
								return(1);
							}
						
							student->aol[j] = *ar;
							student->aol[j].cap = student->aol[j].cap * 2;
							// end of resize
						}
						student->aol[j].arr[student->aol[j].size] = *str2;
						student->aol[j].size++;
						// end of add to end arrayList
					}
		// No Match
				}	
				// will make a add to end fullList function for this
				if (student->size == student->cap)	{
					// resize func
					fullList * fl = realloc(student, (student->cap * 2 *sizeof(arrayList));
				
					if (fl == NULL)	{
						printf("realloc fail\n");
						return(1);
					}
					
					student = *fl;
					// end of resize
				}
				student->aol[student->size].arr[student->aol[student->size].size] = *str2;
				student->aol[student->size].size++;
				student->size++;
						
						// end of add to end fulList
						
						
						
					
			
				
			}
			else	{
				
		}
		
		
	}
	
	free(str1);
	free(str2);
	free(student);
	free(symptom);
	return(0);
}	
	