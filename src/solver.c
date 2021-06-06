#include "solver.h"
#include "stack.h"
#include <stdlib.h>
#include <sys/_types/_size_t.h>

/* void solve(t_stack *stack_a, t_stack *stack_b, int *input) { */
/* 	sort(input); */
/* 	push_chunks(stack_a, stack_b, input); */
/* 	send_all(stack_b, stack_a); */
/* } */

/* void push_chunks(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr) { */
/* 	t_slice *chunk; */
/* 	size_t l; */
/* 	size_t chunk_l; */

/* 	l =  stack_src->length; */
/* 	chunk_l = chunk_l <= 150 ? 15 : 39; */
/* 	while ((chunk = get_next_slice(sorted_arr, l, chunk_l))) { */
/* 		push_chunk(stack_src, stack_dst, chunk); */
/* 		free(chunk); */
/* 	} */
/* } */

/*
** NOTE: t_slice.end is exclusive
** NOTE: don't forget to free t_slice
*/

static void print_slice(t_slice *slice) {
	size_t i;
	i = slice->start;

	while (i < slice->end) {
		printf("%d\n", slice->data[i]);
		i++;
	}
}

t_slice *get_next_slice(int *arr, size_t size, size_t max_chunk_size) {
	t_slice *slice;
	static size_t global_i;
	size_t local_i;

	slice = malloc(sizeof(t_slice));
	slice->data = arr;
	slice->start = global_i;
	slice->end = global_i;
	local_i = 0;
	while (global_i < size) {
		slice->end++;
		global_i++;
		local_i++;
		if (local_i == max_chunk_size || global_i == size) {
			return (slice);
		}
	}
	free(slice);
	return (NULL);
}
