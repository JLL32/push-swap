#ifndef UTILS_H
# define UTILS_H
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atoi(const char *str);
void	put_str_suffix_line(const char *str, const char *suffix);
void	putchar(char c);
char    *ft_strjoin(char const *s1, char const *s2);
int		put_nbr(int n);
#endif
