#include "slice.h"
#include "solver.h"
#include "stack.h"
#include <sys/_types/_size_t.h>

void	push_slices(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr)
{
	t_slice	*slice;
	size_t	arr_length;
	size_t	slice_length;

	arr_length = stack_src->length;
	if (stack_src->length <= 150)
		slice_length = 21;
	else
		slice_length = 40;
	slice = get_next_slice(sorted_arr, arr_length, slice_length);
	while (slice)
	{
		push_slice(stack_src, stack_dst, slice);
		free(slice);
		slice = get_next_slice(sorted_arr, arr_length, slice_length);
	}
}

static t_val_index	fetch_hold_top(t_stack *stack, t_slice *slice)
{
	t_val_index	hold_top;
	size_t		i;

	i = stack->length;
	while (i--)
	{
		hold_top = (t_val_index){get_value_at(stack, i), i};
		if (slice_includes(slice, hold_top.value))
			break ;
	}
	return (hold_top);
}

static t_val_index	fetch_hold_bottom(t_stack *stack, t_slice *slice)
{
	t_val_index	hold_bottom;
	size_t		i;

	i = 0;
	while (i < stack->length)
	{
		hold_bottom = (t_val_index){get_value_at(stack, i), i};
		if (slice_includes(slice, hold_bottom.value))
			break ;
		i++;
	}
	return (hold_bottom);
}

void	push_slice(t_stack *stack_src, t_stack *stack_dst, t_slice *slice)
{
	t_val_index	hold_top;
	t_val_index	hold_bottom;
	size_t		length;

	length = slice->end - slice->start;
	while (length--)
	{
		hold_top = fetch_hold_top(stack_src, slice);
		hold_bottom = fetch_hold_bottom(stack_src, slice);
		if ((long)(stack_src->length - 1 - hold_top.index) - 2 <=
			(long)hold_bottom.index)
			send_from_top(stack_src, stack_dst, hold_top.value);
		else
			send_from_bottom(stack_src, stack_dst, hold_bottom.value);
		if (stack_dst->bottom->value > stack_dst->top->value)
			rotate(stack_dst, true);
	}
}
