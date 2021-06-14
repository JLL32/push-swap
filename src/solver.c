#include "solver.h"
#include "stack.h"
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
			reverse_rotate(stack_a);
		else if (stack_a->bottom->value > get_value_at(stack_a, 1) &&
				 get_value_at(stack_a, 1) < stack_a->top->value &&
				 stack_a->top->value > stack_a->bottom->value)
			rotate(stack_a);
		else
			swap(stack_a);
	}
}

void print_slice(t_slice *slice)
{
	size_t i;
	i = slice->start;

	while (i < slice->end)
	{
		printf("%d\n", slice->data[i]);
		i++;
	}
}

void solve(t_stack *stack_a, t_stack *stack_b, int *input)
{
	sort(input, stack_a->length);
	push_chunks(stack_a, stack_b, input);
	send_all_greatest(stack_b, stack_a);
}

void sort_three(t_stack *stack)
{
	if (stack->top->value > stack->top->prev->value && stack->bottom->value > stack->top->value)
		swap(stack);
	else if (stack->top->value > stack->bottom->value && stack->top->value > stack->top->prev->value)
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (stack->bottom->value > stack->top->value && stack->top->value > stack->top->prev->value)
		rotate(stack);
	else if (stack->top->prev->value > stack->bottom->value && stack->bottom->value > stack->top->value)
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->top->value > stack->bottom->value && stack->top->prev->value > stack->top->value)
		reverse_rotate(stack);
}

void send_all_greatest(t_stack *stack_src, t_stack *stack_dst)
{
	while (stack_src->length)
	{
		send_greatest(stack_src, stack_dst);
	}
}

void send_greatest(t_stack *stack_src, t_stack *stack_dst)
{
	t_val_index biggest;
	t_node *curr_node;
	size_t i;

	biggest = (t_val_index){INT32_MIN, 0};
	curr_node = stack_src->bottom;
	i = 0;
	while (curr_node)
	{
		if (curr_node->value > biggest.value)
		{
			biggest.value = curr_node->value;
			biggest.index = i;
		}
		i++;
		curr_node = curr_node->next;
	}
	if ((double)biggest.index >= ((double)stack_src->length / 2))
		send_from_top(stack_src, stack_dst, biggest.value);
	else
		send_from_bottom(stack_src, stack_dst, biggest.value);
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

static void swapp(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sort(int *arr, size_t size)
{
	size_t i, j;
	for (i = 0; i < size - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] < arr[j + 1])
				swapp(&arr[j], &arr[j + 1]);
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

/*
** NOTE: t_slice.end is exclusive
** NOTE: don't forget to free t_slice
*/

bool slice_includes(t_slice *slice, int value)
{
	size_t i;
	i = slice->start;

	while (i < slice->end)
	{
		if (slice->data[i] == value)
			return (true);
		i++;
	}
	return (false);
}

t_slice *get_next_slice(int *arr, size_t size, size_t max_chunk_size)
{
	t_slice *slice;
	static size_t global_i;
	size_t local_i;

	slice = malloc(sizeof(t_slice));
	slice->data = arr;
	slice->start = global_i;
	slice->end = global_i;
	local_i = 0;
	while (global_i < size)
	{
		slice->end++;
		global_i++;
		local_i++;
		if (local_i == max_chunk_size || global_i == size)
		{
			return (slice);
		}
	}
	free(slice);
	return (NULL);
}
