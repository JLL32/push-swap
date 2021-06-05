#include "solver.h"
#include "stack.h"

void solve(t_stack *stack_a, t_stack *stack_b, int *input) {
	sort(input);
	push_chunks(stack_a, stack_b, input);
	send_all(stack_b, stack_a);
}
