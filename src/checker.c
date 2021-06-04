#include "stack.h"
#include "get_next_line/get_next_line.h"
#include <string.h>


int    *arg_stack_to_int(char **av, size_t size)
{

    int *arr;
    int i = 1;
    arr = malloc(sizeof(int) * size);
    while (av[i]) {
        arr[i - 1] = atoi(av[i]);
        i++;
    }

    return arr;
}

int     main(int ac, char **av)
{
    char *line;
    const char **ops;
    int i;

    i = 0;

    t_stack *stack_a = new_stack("a");
    t_stack *stack_b = new_stack("b");
    int *arr = arg_stack_to_int(av, ac - 1);
    fill_stack(stack_a, arr, ac - 1);
    print_stack(stack_a, false);
    while(get_next_line(0, &line) > 0) {
        ops = realloc(ops, sizeof(ops) + 1);
        ops[i] = line;
        i++;
    }
    free(line);
 //   execute_ops(ops);
    return 0;
}