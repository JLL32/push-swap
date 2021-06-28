#include "utils.h"
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

int	ft_strcmp(const char *x, const char *y)
{
	while (*x)
	{
		if (*x != *y)
			break ;
		x++;
		y++;
	}
	return (*(const unsigned char *) x - *(const unsigned char *) y);
}


long	ft_atoi(const char *str)
{
	int				j;
	long			res;
	long			sign;

	sign = 1;
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
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		res = res * 10 + *(str + j++) - '0';
	return (res * sign);
}

void	put_str_suffix_line(const char *str, const char *suffix)
{
	write(1, str, ft_strlen(str));
	write(1, suffix, ft_strlen(suffix));
	write(1, "\n", 1);
}
