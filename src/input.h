#ifndef INPUT_H
# define INPUT_H
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	panic(char *msg);
int		*input_from_arg(int argc, char **argv);
void	sort_arr(int *arr, size_t size);
void	print_array(int arr[], int size);
#endif
