#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAXINT 2147483647
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
void		*ft_char_calloc(size_t i);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
#endif
