#include "solver.h"
#include "stack.h"
#include <stdlib.h>
#include <sys/_types/_size_t.h>

void solve(t_stack *stack_a, t_stack *stack_b, int *input) {
	sort(input);
	push_chunks(stack_a, stack_b, input);
	send_all(stack_b, stack_a);
}

void push_chunks(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr) {
	int *chunk;
	size_t l;
	size_t chunk_l;

	l =  stack_src->length;
	chunk_l = chunk_l <= 150 ? 15 : 39;
	while ((chunk = get_next_slice(sorted_arr, l, chunk_l))) {
		push_chunk(stack_src, stack_dst, chunk);
	}
}

int *get_next_slice(int *arr, size_t size, size_t max_chunk_size) {
	int *chunk;
	static size_t arr_l;
	size_t start_i;

	chunk = malloc(sizeof(int));
	arr_l = size;
	start_i = 0;
	while (arr_l && ) {
	statements
	}
}
