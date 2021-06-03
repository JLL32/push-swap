#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
	t_stack *stack = new_stack("a");
	fill_stack(stack, (int[]){1, 2, 3, 4}, 4);

	pop_bottom(stack);
	pop_top(stack);
	printf("---forward---\n");
	print_stack(stack, false);
	printf("---backward---\n");
	print_stack(stack, true);

	delete_stack(stack);

	return 0;
}
