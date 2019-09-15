#include <stdio.h>
#include <stdlib.h>

typedef struct array_list {
	int size;
	int cap;
	int* values;
} array_list;

array_list* makeArrayList (int cap)	;
void resize(array_list * al, int newCap);	
void addToEnd(array_list* al, int val);

int main()	{

	array_list * arr = makeArrayList(2);
	addToEnd(arr, 1);
	addToEnd(arr, 2);
	addToEnd(arr, 3);
	
	printf("%d", arr->values[0]);
	printf("%d", arr->values[1]);
	printf("%d", arr->values[2]);
	
}
array_list* makeArrayList (int cap)	{
	
	array_list* ret;
	ret = calloc(1, sizeof(array_list));
	ret->values = calloc(cap, sizeof(int));
	ret->cap    = cap;
	ret->size   = 0;
	return ret;
}

void resize(array_list* al, int newCap)	{
	
	al->values = realloc(al->values, newCap*sizeof(int));
	al->cap = newCap;
}

void addToEnd(array_list* al, int val)	{
	
	if (al->cap == al->size)	{
			resize (al, (al->cap)*2);
	}
	al->values[al->size] = val;
	al->size++;
	
}

