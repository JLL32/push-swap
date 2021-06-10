#include "input-utils.h"

void panic(char *msg) {
	write(2, msg, strlen(msg));
	exit(EXIT_FAILURE);
}

void reverse_arr(int *arr, size_t size)
{
	size_t start;
	int temp;
	size_t end;

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

bool is_number(char *str)
{
	size_t i;
	size_t str_l;

	str_l = strlen(str);
	i = 0;
	while (i < str_l) {
		if (str[i] < 48 || str[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

bool is_dup(int *arr, size_t size, int value)
{
	size_t i;

	i = 0;
	while(i < size) {
		if (value == arr[i])
			return (true);
		i++;
	}
	return (false);
}

int *input_from_arg(int argc, char **argv) {
	int *res;
	size_t i;
	size_t count;

	count = argc - 1;
	argv++;

	res = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		if (!is_number(*argv) || is_dup(res, i, atoi(*argv)))
		{
			free(res);
			panic("Error\n");
		}
		res[i] = atoi(*argv);
		i++;
		argv++;
	}
	reverse_arr(res, count);
	return (res);
}
