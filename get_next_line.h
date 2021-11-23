#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE//ワカモレで記載するかは不明
# define BUFFER_SIZE 1//
#endif

char    *ft_strchr(char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(char *str);
char    *ft_strdup(char *s1);
size_t ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*get_next_line_core(int fd, size_t buffer_size);
char	*get_next_line(int fd);

#endif