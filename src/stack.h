#include <ctype.h>
#include <malloc/_malloc.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_node {
	int value;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_stack {
	t_node *bottom;
	t_node *top;
	size_t length;
	char *label;
} t_stack;

t_node *new_node(int value);
t_stack *new_stack(char *label);
t_node *delete_node(t_node *node);
void delete_stack(t_stack *stack);

void append(t_stack *stack, int value);
void prepend(t_stack *stack, int value);
void fill_stack(t_stack *stack, int *array, size_t size);

