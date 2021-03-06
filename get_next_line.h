#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_gnl_status
{
	char	*buffer;
	size_t	next_n;
}	t_gnl_status;

typedef struct s_gnl_status_var
{
	int		fd;
	char	*ans;
}	t_gnl_status_var;

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		file_read(t_gnl_status *status, t_gnl_status_var *status_var);
int		organizer(t_gnl_status *st, t_gnl_status_var *status_var);
int		loop_handler(t_gnl_status *status, t_gnl_status_var *status_var);
char	*get_next_line(int fd);

#endif