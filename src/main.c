#include "stack.h"
#include "solver.h"
#include "input-utils.h"

void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}

// TODO: check if sorted first
int main(int argc, char **argv)
{
	int *input;
	t_stack *stack_a;
	t_stack *stack_b;

	input = input_from_arg(argc, argv);
	stack_a = new_stack("a");
	stack_b = new_stack("b");
	fill_stack(stack_a, input, argc - 1);
	if (argc == 4)
		solve_three(stack_a);
	else
		solve(stack_a, stack_b, input);
	print_stack(stack_a, true);
	//print_stack(stack_a, true);
	// print_stack(stack_b, true);
	//sort(input, argc-1);
	//printArray(input, argc-1);
	delete_stack(stack_a);
	delete_stack(stack_b);
	free(input);
	return (0);
}
