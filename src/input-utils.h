#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H
# include <stdbool.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void panic(char *msg);
int *input_from_arg(int argc, char **argv);
void sort_arr(int *arr, size_t size);
void print_array(int arr[], int size);
#endif
