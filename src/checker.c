#include "stack.h"
#include "get_next_line/get_next_line.h"
#include "input-utils.h"

int execute_ops(char **ops, t_stack *stack_a, t_stack *stack_b)
{
    int i;

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
            return -1;
        i++;
    }
    return 1;
}

bool is_sorted(t_stack *stack_a)
{
    t_node *curr_node = stack_a->bottom;
    while (curr_node)
    {
        if (curr_node->next)
            if (curr_node->value < curr_node->next->value)
                return false;
        curr_node = curr_node->next;
    }
    return true;
}

int main(int argc, char **argv)
{
    char *line;
    char **ops;
    int i;

    i = 0;
	// you might ask why i moved the statement below to the top
	// try to figure it out on your own ;)
    int *input = input_from_arg(argc - 1, argv);
    t_stack *stack_a = new_stack("a");
    t_stack *stack_b = new_stack("b");
    fill_stack(stack_a, input, argc - 1);
    print_stack(stack_a, false);
    ops = malloc(sizeof(*ops));
    while (get_next_line(0, &line) > 0)
    {
        ops[i] = line;
        i++;
        ops = realloc(ops, i*sizeof(*ops) + sizeof(*ops));
    }
    ops[i] = NULL;
    free(line);
    if (execute_ops(ops, stack_a, stack_b) == -1)
    {
        write(2, "Error\n", 6);
        // free_memory(stack_a, stack_b, ops, arr);
    }
    if (is_sorted(stack_a))
        write(1, "OK", 2);
    else
        write(1, "KO", 2);
    return 0;
}
