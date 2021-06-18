#include "utils.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

static int	ft_memncmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < (int)n - 1 && *(str1 + i) == *(str2 + i))
	{
		if ((*(str1 + i) || *(str2 + i)) == '\0')
			break ;
		i++;
	}
	return (*(str1 + i) - *(str2 + i));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_memncmp(s1, s2, n));
}

int	ft_atoi(const char *str)
{
	int				j;
	unsigned long	res;
	int				temp;

	temp = 1;
	j = 0;
	res = 0;
	while (*str > 0 && *str <= 32)
	{
		if (*str == 27)
			return (0);
		str++;
	}
	if (*str == '-')
	{
		temp = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		res = res * 10 + *(str + j++) - '0';
	return (res * temp);
}
