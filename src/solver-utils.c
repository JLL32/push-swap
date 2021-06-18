#include "solver.h"
#include "utils.h"

void	send_extrema(t_stack *stack_src,
					t_stack *stack_dst,
					int comparer(int a, int b),
					int extrema)
{
	t_val_index	holder;
	t_node		*curr_node;
	size_t		i;

	holder = (t_val_index){extrema, 0};
	curr_node = stack_src->bottom;
	i = 0;
	while (curr_node)
	{
		if (comparer(curr_node->value, holder.value))
		{
			holder.value = curr_node->value;
			holder.index = i;
		}
		i++;
		curr_node = curr_node->next;
	}
	if ((double)holder.index >= ((double)stack_src->length / 2))
		send_from_top(stack_src, stack_dst, holder.value);
	else
		send_from_bottom(stack_src, stack_dst, holder.value);
}

static int	comparer_greatest(int a, int b)
{
	return (a > b);
}

void	send_all_greatest(t_stack *stack_src, t_stack *stack_dst)
{
	while (stack_src->length)
	{
		send_extrema(stack_src, stack_dst, comparer_greatest, INT32_MIN);
	}
}

void	send_from_top(t_stack *stack_src, t_stack *stack_dst, int value)
{
	while (stack_src->top->value != value)
	{
		if (ft_strncmp(stack_src->label, "b", ft_strlen(stack_src->label)) == 0
			&& (stack_src->top->prev)
			&& stack_src->top->prev->value == value)
			swap(stack_src, true);
		else
			rotate(stack_src, true);
	}
	send(stack_src, stack_dst, true);
}

void	send_from_bottom(t_stack *stack_src, t_stack *stack_dst, int value)
{
	if (stack_src->top == NULL)
		return ;
	while (stack_src->top->value != value)
	{
		reverse_rotate(stack_src, true);
	}
	send(stack_src, stack_dst, true);
}
