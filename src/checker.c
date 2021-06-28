#include "stack.h"
#include "get_next_line/get_next_line.h"
#include "input.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	execute_ops(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "ra\n") == 0)
		rotate(stack_a, false);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(stack_b, false);
	else if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate(stack_a, false);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate(stack_b, false);
	else if (ft_strcmp(op, "sa\n") == 0)
		swap(stack_a, false);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(stack_b, false);
	else if (ft_strcmp(op, "pa\n") == 0)
		send(stack_b, stack_a, false);
	else if (ft_strcmp(op, "pb\n") == 0)
		send(stack_a, stack_b, false);
	else if (ft_strcmp(op, "ss\n") == 0)
		swap_both(stack_a, stack_b, false);
	else if (ft_strcmp(op, "rr\n") == 0)
		rotate_both(stack_a, stack_b, false);
	else if (ft_strcmp(op, "rrr\n") == 0)
		reverse_rotate_both(stack_a, stack_b, false);
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

char	*ft_getline(void)
{
	char	c;
	char	*line;
	char	*tmp;

	line = malloc(1);
	*line = '\0';
	while (1)
	{
		if (!read(0, &c, 1))
		{
			tmp = line;
			line = ft_strjoin(tmp, "EOF");
			free(tmp);
			return (line);
		}
		tmp = line;
		line = ft_strjoin(tmp, (char [2]){c, '\0'});
		free(tmp);
		if (c == '\n')
			return (line);
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*input;
	int		i;

	i = 0;
	input = input_from_arg(argc, argv);
	stack_a = new_stack("a");
	stack_b = new_stack("b");
	fill_stack(stack_a, input, argc - 1);
	while (1)
	{
		line = ft_getline();
		i++;
		if (ft_strcmp(line, "EOF") == 0) {
			break;
		}
		if (*line == '\0' || execute_ops(line, stack_a, stack_b) == -1)
		{
			write(2, "Error\n", 6);
			free_memory(stack_a, stack_b, line, input);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	if (is_sorted(stack_a) && stack_b->length == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_memory(stack_a, stack_b, line, input);
	return (0);
}
