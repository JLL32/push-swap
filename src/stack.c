#include "./stack.h"
#include <sys/_types/_size_t.h>

t_node *new_node(int value)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack *new_stack(char *label)
{
	t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->length = 0;
	stack->label = label;
	return (stack);
}

// NOTE: deletes the given node and returns the next one
// and by deleting I mean clearing and freeing
t_node *delete_node(t_node *node)
{
	t_node *temp = node;
	node = node->next;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
	return (node);
}

void delete_stack(t_stack *stack)
{
	t_node *curr_node = stack->bottom;
	while (curr_node)
	{
		curr_node = delete_node(curr_node);
	}
	stack->bottom = NULL;
	stack->top = NULL;
	stack->length = 0;
	stack->label = "";
	free(stack);
}

void swap(t_stack *stack, bool display)
{
	int tmp;

	if (display)
		printf("s%s\n", stack->label);
	if (stack->length > 1)
	{
		tmp = stack->top->value;
		stack->top->value = stack->top->prev->value;
		stack->top->prev->value = tmp;
	}
}

void append(t_stack *stack, int value)
{
	t_node *node = new_node(value);
	if (stack->bottom == NULL)
	{
		stack->bottom = node;
		stack->top = stack->bottom;
	}
	else
	{
		node->prev = stack->top;
		stack->top->next = node;
		stack->top = node;
	}
	stack->length++;
}

void prepend(t_stack *stack, int value)
{
	t_node *node = new_node(value);
	if (stack->bottom == NULL)
	{
		stack->bottom = node;
		stack->top = stack->bottom;
	}
	else
	{
		node->next = stack->bottom;
		stack->bottom->prev = node;
		stack->bottom = node;
	}
	stack->length++;
}

// CAUTION: DO NOT CALL if length == 0
int pop_top(t_stack *stack)
{
	t_node *temp;
	int val;

	if (stack->length == 1)
	{
		val = stack->bottom->value;
		temp = stack->bottom;
		stack->bottom = stack->top = NULL;
		free(temp);
	}
	else
	{
		val = stack->top->value;
		temp = stack->top;
		stack->top = temp->prev;
		stack->top->next = NULL;
		free(temp);
	}
	stack->length--;

	return (val);
}

// CAUTION: DO NOT CALL if length == 0
int pop_bottom(t_stack *stack)
{
	t_node *temp;
	int val;

	val = stack->bottom->value;
	if (stack->length == 1)
	{
		temp = stack->bottom;
		stack->bottom = stack->top = NULL;
		free(temp);
	}
	else
	{
		temp = stack->bottom->next;
		free(stack->bottom);
		stack->bottom = NULL;
		temp->prev = NULL;
		stack->bottom = temp;
	}
	stack->length--;
	return (val);
}

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

void rotate(t_stack *stack, bool display)
{
	if (display)
		printf("r%s\n", stack->label);
	if (stack->length > 1)
	{
		prepend(stack, pop_top(stack));
	}
}

void reverse_rotate(t_stack *stack, bool display)
{
	if (display)
		printf("rr%s\n", stack->label);
	if (stack->length > 1)
	{
		append(stack, pop_bottom(stack));
	}
}

void send(t_stack *stack_src, t_stack *stack_dst, bool display)
{
	if (display)
		printf("p%s\n", stack_dst->label);
	append(stack_dst, pop_top(stack_src));
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
