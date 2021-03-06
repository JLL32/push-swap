#include "stack.h"
#include "utils.h"

void	swap(t_stack *stack, bool display)
{
	int	tmp;

	if (stack->length > 1)
	{
		tmp = stack->top->value;
		stack->top->value = stack->top->prev->value;
		stack->top->prev->value = tmp;
		if (display)
			put_str_suffix_line("s", stack->label);
	}
}

void	rotate(t_stack *stack, bool display)
{
	if (stack->length > 1)
	{
		prepend(stack, pop_top(stack));
		if (display)
			put_str_suffix_line("r", stack->label);
	}
}

void	reverse_rotate(t_stack *stack, bool display)
{
	if (stack->length > 1)
	{
		append(stack, pop_bottom(stack));
		if (display)
			put_str_suffix_line("rr", stack->label);
	}
}

void	send(t_stack *stack_src, t_stack *stack_dst, bool display)
{
	if (stack_src->length >= 1)
	{
		append(stack_dst, pop_top(stack_src));
		if (display)
			put_str_suffix_line("p", stack_dst->label);
	}
}
