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

