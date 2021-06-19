#ifndef SLICE_H
# define SLICE_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_slice
{
	const int	*data;
	size_t		start;
	size_t		end;
}			t_slice;

t_slice		*get_next_slice(int *arr, size_t size, size_t max_slice_size);
bool		slice_includes(t_slice *slice, int value);
void		print_slice(t_slice *slice);
#endif
