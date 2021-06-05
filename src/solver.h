#include "stack.h"
#include <malloc/_malloc.h>

void solve(t_stack *stack_a, t_stack *stack_b, int *input);
void send_from_top(t_stack *stack_src, t_stack *stack_dst, int value);
void send_from_bottom(t_stack *stack_src, t_stack *stack_dst, int value);
void send_biggest(t_stack *stack_src, t_stack *stack_dst);
void send_all(t_stack *stack_src, t_stack *stack_dst);
void push_chunk(t_stack *stack_src, t_stack *stack_dst, int *chunk);
void push_chunks(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr);
void sort(int *arr);
