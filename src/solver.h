#ifndef SOLVER_H
# define SOLVER_H
# include "input.h"
# include "slice.h"
# include "stack.h"
# include <malloc/_malloc.h>
# include <sys/_types/_size_t.h>

typedef struct s__val_index
{
	int			value;
	size_t		index;
}		t_val_index;

void	solve(t_stack *stack_a, t_stack *stack_b, int *input);
void	send_from_top(t_stack *stack_src, t_stack *stack_dst, int value);
void	send_from_bottom(t_stack *stack_src, t_stack *stack_dst, int value);
void	send_extrema(t_stack *stack_src,
			t_stack *stack_dst,
			int comparer(int a, int b),
			int extrema);
void	send_all_greatest(t_stack *stack_src, t_stack *stack_dst);
void	push_slice(t_stack *stack_src, t_stack *stack_dst, t_slice *slice);
void	push_slices(t_stack *stack_src, t_stack *stack_dst, int *sorted_arr);
void	sort(int *arr, size_t size);
void	sort_three(t_stack *stack);
void	solve_three(t_stack *stack_a);
void	solve_five(t_stack *stack_a, t_stack *stack_b);
#endif
