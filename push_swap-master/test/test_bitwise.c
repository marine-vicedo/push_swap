#include <stdio.h>

int	main (void)
{
	int nbr = 87;
	int a = 6;
	int b = 5;

	//test the operator >> (right shift)
	printf("%d\n", nbr>>3);

	//test the operator & (Bitwise AND)
	printf("%d\n", a&b);
}