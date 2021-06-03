#include "stack.h"
#include <stdio.h>

int main() {
	t_stack *stack = new_stack("a");
	fill_stack(stack, (int[]){1, 2, 3, 4}, 4);
	t_node *curr_node = stack->bottom;

	prepend(stack, 0);
	while (curr_node) {
		printf("value: %d \n", curr_node->value);
		curr_node = curr_node->next;
	}
	printf("-------\n");
	curr_node = stack->top;
	while (curr_node) {
		printf("value: %d \n", curr_node->value);
		curr_node = curr_node->prev;
	}


	return 0;
}
