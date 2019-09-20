/* 
* Attempting to calculate large exponents that are then muduloed using recursion 
* Used in encryption
*/

/* Psuedo - Code *********************************

using the format: (a ^ b)mod c

need a recursive function that will take b and split it in half if even

long long int foo(int a, int b, int, c)	

	
	while (b is not 1)
		 if (b is even)
			
			cut b in half;
			return foo(a, b, c)
		else if (b is odd)
			
			b = b -1 
			cut b in half;
			return a * foo(a, b, c)
			
			
*****************************************************/

/*		***********NOTES************

	Seems toi be working, still need to check tho code on webcourses to make sure im doing the right thing

*/




#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

lli foo (int, int, int);

int main ()	{
	
	lli solution = foo(4, 100, 19);
	printf("%lli", solution);
	return (0);
	
}

lli foo (int a , int b, int c)	{
	
	while (b != 1)	{
		if (b % 2 == 0)	{
			return a * foo(a, (b/2), c) % c;
		}
		else if (b % 2 != 0)	{
			return a * foo(a, ((b - 1) / 2), c) % c;
		}
	}
	return (1);
}