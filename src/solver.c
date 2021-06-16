#include "solver.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>

int comparer_greatest(int a, int b)
{
	return (a > b);
}

int comparer_smallest(int a, int b)
{
	return (b > a);
}

void solve_three(t_stack *stack_a)
{
	while (!is_sorted(stack_a))
	{
		if (stack_a->bottom->value < get_value_at(stack_a, 1) &&
			get_value_at(stack_a, 1) > stack_a->top->value &&
			stack_a->bottom->value < stack_a->top->value)
			reverse_rotate(stack_a);
		else if (stack_a->bottom->value > get_value_at(stack_a, 1) &&
				 get_value_at(stack_a, 1) < stack_a->top->value &&
				 stack_a->top->value > stack_a->bottom->value)
			rotate(stack_a);
		else
			swap(stack_a);
	}
}

void solve_five(t_stack *stack_a, t_stack *stack_b)
{
	send_extrema(stack_a, stack_b, comparer_smallest, INT32_MAX);
	send_extrema(stack_a, stack_b, comparer_smallest, INT32_MAX);
	solve_three(stack_a);
	send(stack_b, stack_a);
	send(stack_b, stack_a);
}


void solve(t_stack *stack_a, t_stack *stack_b, int *input)
{
	sort_arr(input, stack_a->length);
	push_chunks(stack_a, stack_b, input);
	send_all_greatest(stack_b, stack_a);
}

void send_extrema(t_stack *stack_src, t_stack *stack_dst,
int comparer(int a, int b), int extrema)
{
	t_val_index holder;
	t_node *curr_node;
	size_t i;

	holder = (t_val_index){extrema, 0};
	curr_node = stack_src->bottom;
	i = 0;
	while (curr_node)
	{
		if (comparer(curr_node->value, holder.value))
		{
			holder.value = curr_node->value;
			holder.index = i;
		}
		i++;
		curr_node = curr_node->next;
	}
	if ((double)holder.index >= ((double)stack_src->length / 2))
		send_from_top(stack_src, stack_dst, holder.value);
	else
		send_from_bottom(stack_src, stack_dst, holder.value);
}

void send_all_greatest(t_stack *stack_src, t_stack *stack_dst)
{
	while (stack_src->length)
	{
		send_extrema(stack_src, stack_dst, comparer_greatest, INT32_MIN);
	}
}

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
			if (hold_bottom.value == 287 && hold_bottom.index == 2)
			{
				printf("");
			}
			if (slice_includes(chunk, hold_bottom.value))
				break;
			i++;
		}
		if ((long)(stack_src->length - 1 - hold_top.index) - 2 <= (long)hold_bottom.index)
			send_from_top(stack_src, stack_dst, hold_top.value);
		else
			send_from_bottom(stack_src, stack_dst, hold_bottom.value);
		if (stack_dst->bottom->value > stack_dst->top->value)
			rotate(stack_dst);
	}
}

void send_from_top(t_stack *stack_src, t_stack *stack_dst, int value)
{
	while (stack_src->top->value != value)
	{
		if (strcmp(stack_src->label, "b") == 0 && (stack_src->top->prev) && stack_src->top->prev->value == value)
			swap(stack_src);
		else
			rotate(stack_src);
	}
	send(stack_src, stack_dst);
}

void send_from_bottom(t_stack *stack_src, t_stack *stack_dst, int value)
{
	if (stack_src->top == NULL)
		return;
	while (stack_src->top->value != value)
	{
		reverse_rotate(stack_src);
	}
	send(stack_src, stack_dst);
}
