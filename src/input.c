#include "input.h"
#include "utils.h"
#include <limits.h>
#include <stdlib.h>

static bool	is_dup(int *arr, size_t size, int value)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (value == arr[i])
			return (true);
		i++;
	}
	return (false);
}

static void	reverse_arr(int *arr, size_t size)
{
	size_t	start;
	int		temp;
	size_t	end;

	if (size < 2)
		return ;
	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

static bool	is_int(char *str)
{
	size_t	i;
	size_t	str_l;

	str_l = ft_strlen(str);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i == 1 && str_l == 1)
		return (false);
	if (str_l > 10 + i
		|| ft_atoi(str) > INT_MAX
		|| ft_atoi(str) < INT_MIN)
	{
		return (false);
	}
	while (i < str_l)
	{
		if (str[i] < 48 || str[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

int	*input_from_arg(int argc, char **argv)
{
	int		*res;
	size_t	i;
	size_t	count;

	count = argc - 1;
	if (count < 1)
		exit(EXIT_SUCCESS);
	argv++;
	res = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		if (!is_int(*argv) || is_dup(res, i, ft_atoi(*argv)))
		{
			free(res);
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(EXIT_FAILURE);
		}
		res[i] = ft_atoi(*argv);
		i++;
		argv++;
	}
	reverse_arr(res, count);
	return (res);
}

void	sort_arr(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
