#include "solver.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>

void solve_three(t_stack *stack_a)
{
	while (!is_sorted(stack_a))
	{
		if (stack_a->bottom->value < get_value_at(stack_a, 1) &&
			get_value_at(stack_a, 1) > stack_a->top->value &&
			stack_a->bottom->value < stack_a->top->value)
			reverse_rotate(stack_a, true);
		else if (stack_a->bottom->value > get_value_at(stack_a, 1) &&
				 get_value_at(stack_a, 1) < stack_a->top->value &&
				 stack_a->top->value > stack_a->bottom->value)
			rotate(stack_a, true);
		else
			swap(stack_a, true);
	}
}

void solve_five(t_stack *stack_a, t_stack *stack_b)
{
	send_extrema(stack_a, stack_b, comparer_smallest, INT32_MAX);
	send_extrema(stack_a, stack_b, comparer_smallest, INT32_MAX);
	solve_three(stack_a);
	send(stack_b, stack_a, true);
	send(stack_b, stack_a, true);
}

void solve(t_stack *stack_a, t_stack *stack_b, int *input)
{
	sort_arr(input, stack_a->length);
	push_chunks(stack_a, stack_b, input);
	send_all_greatest(stack_b, stack_a);
}
