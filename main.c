#include <stdio.h>

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
	printf("%i\n", ft_studying_xor(1, 5, 3));
	printf("%i\n", (2 < 1) ^ (2 < 3));
}