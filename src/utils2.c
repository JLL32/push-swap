#include "utils.h"

void	putchar(char c)
{
	write(1, &c, 1);
}

int	put_nbr(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		put_nbr(n / 10);
		putchar(n % 10 + '0');
	}
	if (n < 10)
	{
		putchar(n % 10 + '0');
	}
	return (n);
}
