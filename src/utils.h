#ifndef UTILS_H
# define UTILS_H
# include <ctype.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	put_str_suffix_line(const char *str, const char *suffix);
void	putchar(char c);
int		put_nbr(int n);
#endif
