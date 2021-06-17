#include "stack.h"

void fill_stack(t_stack *stack, int *array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		append(stack, array[i]);
		i++;
	}
}

// CAUTION: don't forget to free when you finish
int *to_array(t_stack *stack)
{
	int *array;
	size_t i;
	t_node *curr_node;

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

// CAUTION: don't call if index >= stack.length
int get_value_at(t_stack *stack, size_t index)
{
	int *arr = to_array(stack);
	int val = arr[index];
	free(arr);
	return (val);
}

void print_stack(t_stack *stack, bool backward)
{
	t_node *curr_node;

	printf("stack_%s ", stack->label);
	if (!backward)
	{
		printf("---forward---\n");
		curr_node = stack->bottom;
		while (curr_node)
		{
			printf("%d \n", curr_node->value);
			curr_node = curr_node->next;
		}
	}
	else
	{
		printf("---backward---\n");
		curr_node = stack->top;
		while (curr_node)
		{
			printf("%d \n", curr_node->value);
			curr_node = curr_node->prev;
		}
	}
}

bool is_sorted(t_stack *stack_a)
{
	t_node *curr_node = stack_a->bottom;
	while (curr_node)
	{
		if (curr_node->next)
			if (curr_node->value < curr_node->next->value)
				return false;
		curr_node = curr_node->next;
	}
	return true;
}
