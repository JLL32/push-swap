#include "slice.h"
#include "utils.h"

/*
** NOTE: t_slice.end is exclusive
** NOTE: don't forget to free t_slice
*/

t_slice	*get_next_slice(int *arr, size_t size, size_t max_slice_size)
{
	t_slice			*slice;
	static size_t	global_i;
	size_t			local_i;

	slice = malloc(sizeof(t_slice));
	slice->data = arr;
	slice->start = global_i;
	slice->end = global_i;
	local_i = 0;
	while (global_i < size)
	{
		slice->end++;
		global_i++;
		local_i++;
		if (local_i == max_slice_size || global_i == size)
		{
			return (slice);
		}
	}
	free(slice);
	return (NULL);
}

bool	slice_includes(t_slice *slice, int value)
{
	size_t	i;

	i = slice->start;
	while (i < slice->end)
	{
		if (slice->data[i] == value)
			return (true);
		i++;
	}
	return (false);
}

void	print_slice(t_slice *slice)
{
	size_t	i;

	i = slice->start;
	while (i < slice->end)
	{
		put_nbr(slice->data[i]);
		putchar('\n');
		i++;
	}
}
