#include "stack.h"
#include "solver.h"
#include "input-utils.h"


// TODO: check if sorted first
int main(int argc, char **argv) {
	int *input;
	t_stack *stack_a;
	t_stack *stack_b;

	input = input_from_arg(argc, argv);
	stack_a = new_stack("a");
	stack_b = new_stack("b");
	fill_stack(stack_a, input, argc - 1);
	print_stack(stack_a, true);
	/* solve(stack_a, stack_b, input); */
	delete_stack(stack_a);
	delete_stack(stack_b);
	free(input);
	return (0);
}
