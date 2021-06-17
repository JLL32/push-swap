#include "solver.h"

void push_chunks(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr)
{
	t_slice *chunk;
	size_t l;
	size_t chunk_l;

	l = stack_src->length;
	chunk_l = stack_src->length <= 150 ? 21 : 40;
	while ((chunk = get_next_slice(sorted_arr, l, chunk_l)))
	{
		push_chunk(stack_src, stack_dst, chunk);
		free(chunk);
	}
}

void push_chunk(t_stack *stack_src, t_stack *stack_dst, t_slice *chunk)
{
	t_val_index hold_top;
	t_val_index hold_bottom;
	size_t length;
	size_t i;

	length = chunk->end - chunk->start;
	while (length--)
	{
		i = stack_src->length;
		while (i--)
		{
			hold_top = (t_val_index){get_value_at(stack_src, i), i};
			if (slice_includes(chunk, hold_top.value))
				break;
		}
		i = 0;
		while (i < stack_src->length)
		{
			hold_bottom = (t_val_index){get_value_at(stack_src, i), i};
			if (slice_includes(chunk, hold_bottom.value))
				break;
			i++;
		}
		if ((long)(stack_src->length - 1 - hold_top.index) - 2 <= (long)hold_bottom.index)
			send_from_top(stack_src, stack_dst, hold_top.value);
		else
			send_from_bottom(stack_src, stack_dst, hold_bottom.value);
		if (stack_dst->bottom->value > stack_dst->top->value)
			rotate(stack_dst, true);
	}
}
