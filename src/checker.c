#include "stack.h"
#include "get_next_line/get_next_line.h"
#include "input.h"
#include "utils.h"
#include <stdlib.h>

static int	execute_ops(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(op, "ra", ft_strlen(op)) == 0)
		rotate(stack_a, false);
	else if (ft_strncmp(op, "rb", ft_strlen(op)) == 0)
		rotate(stack_b, false);
	else if (ft_strncmp(op, "rra", ft_strlen(op)) == 0)
		reverse_rotate(stack_a, false);
	else if (ft_strncmp(op, "rrb", ft_strlen(op)) == 0)
		reverse_rotate(stack_b, false);
	else if (ft_strncmp(op, "sa", ft_strlen(op)) == 0)
		swap(stack_a, false);
	else if (ft_strncmp(op, "sb", ft_strlen(op)) == 0)
		swap(stack_b, false);
	else if (ft_strncmp(op, "pa", ft_strlen(op)) == 0)
		send(stack_b, stack_a, false);
	else if (ft_strncmp(op, "pb", ft_strlen(op)) == 0)
		send(stack_a, stack_b, false);
	else
		return (-1);
	return (1);
}

static void	free_memory(t_stack *stack_a, t_stack *stack_b, char *op, int *arr)
{
	delete_stack(stack_a);
	delete_stack(stack_b);
	free(op);
	free(arr);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*input;

	input = input_from_arg(argc, argv);
	stack_a = new_stack("a");
	stack_b = new_stack("b");
	fill_stack(stack_a, input, argc - 1);
	while (get_next_line(0, &line) > 0)
	{
		if (execute_ops(line, stack_a, stack_b) == -1)
		{
			write(2, "Error\n", 6);
			free_memory(stack_a, stack_b, line, input);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_memory(stack_a, stack_b, line, input);
	return (0);
}
