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

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *strjoin;
    size_t  len;
    size_t  i;

    i = 0;
    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    strjoin = malloc((sizeof(char) * len) + sizeof(char));
    if (!strjoin)
        return (NULL);
    while (*s1)
        strjoin[i++] = *(s1++);
    while (*s2)
        strjoin[i++] = *(s2++);
    strjoin[i] = '\0';
    return (strjoin);
}

