#include "stack.h"
#include <malloc/_malloc.h>
#include <sys/_types/_size_t.h>

typedef struct s_slice {
	const int *data;
	size_t start;
	size_t end;
} t_slice;

void solve(t_stack *stack_a, t_stack *stack_b, int *input);
void send_from_top(t_stack *stack_src, t_stack *stack_dst, int value);
void send_from_bottom(t_stack *stack_src, t_stack *stack_dst, int value);
void send_biggest(t_stack *stack_src, t_stack *stack_dst);
void send_all(t_stack *stack_src, t_stack *stack_dst);
t_slice *get_next_slice(int *arr, size_t size, size_t max_chunk_size);
void push_chunk(t_stack *stack_src, t_stack *stack_dst, t_slice *chunk);
void push_chunks(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr);
void sort(int *arr);
