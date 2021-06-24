#include "stack.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b, bool display)
{
	swap(stack_a, false);
	swap(stack_b, false);
	if (display)
		write(1, "ss", 2);
}

void	rotate_both(t_stack *stack_a, t_stack*stack_b, bool display)
{
	rotate(stack_a, false);
	rotate(stack_b, false);
	if (display)
		write(1, "rr", 2);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, bool display)
{
	reverse_rotate(stack_a, false);
	reverse_rotate(stack_b, false);
	if (display)
		write(1, "rrr", 2);
}
