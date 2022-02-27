#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_pick_pivot(int a, int b, int c)
{
	if ((a > b) ^ (a > c))
		return (a);
	else if ((b < a) ^ (b < c))
		return (b);
	else
		return (c);
}
int	ft_studying_xor(int a, int b, int c)
{
	if ((a > b) ^ (a > c))
		return (a);
	else if ((b < a) ^ (b < c))
		return (b);
	else
		return (c);
}

int main (void)
{
	int **test;

	test = (int **)malloc(sizeof(int *) * 4);

	test[0] = NULL;
	test[1] = (int *)malloc(sizeof(int));
	test[1][0] = 42;
	printf("%i\n", ft_studying_xor(1, 5, 3));
	printf("%i\n", (2 < 1) ^ (2 < 3));
}