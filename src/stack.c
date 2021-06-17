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
