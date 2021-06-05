#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H
# include <stdbool.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void panic(char *msg);
void reverse_arr(int *arr, size_t size);
bool is_number(char *str);
bool is_dup(int *arr, size_t size, int value);
int *input_from_arg(int argc, char **argv);
#endif
