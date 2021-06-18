#include "input.h"
#include "solver.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	int		*input;
	t_stack	*stack_a;
	t_stack	*stack_b;

	input = input_from_arg(argc, argv);
	stack_a = new_stack("a");
	stack_b = new_stack("b");
	fill_stack(stack_a, input, argc - 1);
	if (is_sorted(stack_a) == false)
	{
		if (stack_a->length == 3)
			solve_three(stack_a);
		else if (stack_a->length == 5)
			solve_five(stack_a, stack_b);
		else
			solve(stack_a, stack_b, input);
	}
	delete_stack(stack_a);
	delete_stack(stack_b);
	free(input);
	return (0);
}
