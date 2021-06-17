#include "stack.h"

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
