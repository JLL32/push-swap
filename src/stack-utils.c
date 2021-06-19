#include "stack.h"
#include "utils.h"
#include <unistd.h>

void	fill_stack(t_stack *stack, int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		append(stack, array[i]);
		i++;
	}
}

/*
** CAUTION: don't forget to free when you finish
*/

int	*to_array(t_stack *stack)
{
	int		*array;
	size_t	i;
	t_node	*curr_node;

	array = malloc(stack->length * sizeof(int));
	curr_node = stack->bottom;
	i = 0;
	while (curr_node)
	{
		array[i] = curr_node->value;
		curr_node = curr_node->next;
		i++;
	}
	return (array);
}

/*
** CAUTION: don't call if index >= stack.length
*/

int	get_value_at(t_stack *stack, size_t index)
{
	int	*arr;
	int	val;

	arr = to_array(stack);
	val = arr[index];
	free(arr);
	return (val);
}

void	print_stack(t_stack *stack, bool backward)
{
	t_node	*curr_node;

	put_str_suffix_line("stack: ", stack->label);
	if (!backward)
	{
		put_str_suffix_line("---forward---", "");
		curr_node = stack->bottom;
		while (curr_node)
		{
			put_nbr(curr_node->value);
			putchar('\n');
			curr_node = curr_node->next;
		}
	}
	else
	{
		put_str_suffix_line("---backward---", "");
		curr_node = stack->top;
		while (curr_node)
		{
			put_nbr(curr_node->value);
			putchar('\n');
			curr_node = curr_node->prev;
		}
	}
}

bool	is_sorted(t_stack *stack_a)
{
	t_node	*curr_node;

	curr_node = stack_a->bottom;
	while (curr_node)
	{
		if (curr_node->next)
			if (curr_node->value < curr_node->next->value)
				return (false);
		curr_node = curr_node->next;
	}
	return (true);
}
