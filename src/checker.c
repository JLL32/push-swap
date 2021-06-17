#include "stack.h"
#include "get_next_line/get_next_line.h"
#include "input-utils.h"

int	execute_ops(char **ops, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (ops[i])
	{
		if (strcmp(ops[i], "ra") == 0)
			rotate(stack_a);
		else if (strcmp(ops[i], "rb") == 0)
			rotate(stack_b);
		else if (strcmp(ops[i], "rra") == 0)
			reverse_rotate(stack_a);
		else if (strcmp(ops[i], "rrb") == 0)
			reverse_rotate(stack_b);
		else if (strcmp(ops[i], "sa") == 0)
			swap(stack_a);
		else if (strcmp(ops[i], "sb") == 0)
			swap(stack_b);
		else if (strcmp(ops[i], "pa") == 0)
			send(stack_b, stack_a);
		else if (strcmp(ops[i], "pb") == 0)
			send(stack_a, stack_b);
		else
			return (-1);
		i++;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr_node;

	curr_node = stack->bottom;
	while (curr_node)
	{
		free(curr_node);
		curr_node = curr_node->next;
	}
	free(stack);
}

void	free_memory(t_stack *stack_a, t_stack *stack_b, char **ops)
{
	int	i;

	i = 0;
	free_stack(stack_a);
	free_stack(stack_b);
	while (ops[i])
	{
		free(ops[i]);
		i++;
	}
	free(ops);
}

int	main(int argc, char **argv)
{
	char	*line;
	char	**ops;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	int *input = input_from_arg(argc, argv);
	stack_a = new_stack("a");
	stack_b = new_stack("b");
	fill_stack(stack_a, input, argc - 1);
	print_stack(stack_a, false);
	ops = malloc(sizeof(*ops));
	while (get_next_line(0, &line) > 0)
	{
		ops[i] = line;
		i++;
		ops = realloc(ops, i * sizeof(*ops) + sizeof(*ops));
	}
	ops[i] = NULL;
	free(line);
	if (execute_ops(ops, stack_a, stack_b) == -1)
	{
		write(2, "Error\n", 6);
		free_memory(stack_a, stack_b, ops);
	}
	free_memory(stack_a, stack_b, ops);
	if (is_sorted(stack_a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	return (0);
}
