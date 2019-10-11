#include <stdio.h>
#include <stdlib.h>


void solve (int height, int source, int dest, int aux);

int main ()	{
	int height, source, dest, aux;
	scanf ("%d %d %d %d", &height, &source, &dest, &aux);
	solve (height, source, dest, aux);
	return (0);


}



void solve (int height, int source, int dest, int aux)	{
	// base case
	if (height == 1)	{
		printf("move disk 1 from %d to %d\n", source, dest);
		return;
	}
	
	
	// move small stack (height -1 ) tower
	solve(height - 1, source, aux, dest);
	
	// move the largwe disk
	printf("move Disk %d from %d to %d\n", height, source, dest);
	
	solve (height - 1, aux, dest, source);


}