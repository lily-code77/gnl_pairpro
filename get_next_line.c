#include<stdio.h>
#include<assert.h>
#include<string.h>
# include <unistd.h>
# include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_gnl_status
{
	char 	*buffer;
	size_t	next_n_index;
}	t_gnl_status;

int	file_read(t_gnl_status *status,int fd, size_t buffer_size)
{
	ssize_t	rc;

	status->next_n_index = 0;
	status->buffer = (char *)malloc((size_t)buffer_size + 1);
	if (status->buffer == NULL)
		return (-1);
	rc = read(fd, status->buffer, buffer_size);
	if (rc <= 0)
	{
		free(status->buffer);
		status->buffer = NULL;
		if (rc == 0)
			return (0);
		return (-1);
	}
	status->buffer[rc] = '\0';
	return (1);
}

char	*get_next_line_core(int fd, size_t buffer_size)
{
	static t_gnl_status status;
	char 				*ans;
	char				*tmp;
	int  				ret;

	ans = NULL;
	while (true)
	{
		if (status.buffer == NULL)
		{
			ret = file_read(&status,fd,buffer_size);
			if (ret < 0)
				break ;
			if (ret == 0)
				return (ans);
		}
		if (ans == NULL)
			ans = ft_strdup("");
		tmp = ft_strjoin(ans, &status.buffer[status.next_n_index]);
		if (tmp == NULL)
			break ;
		free(ans);
		ans = tmp;
		if (ft_strchr(&status.buffer[status.next_n_index], '\n'))
		{
			status.next_n_index = ft_strchr(&status.buffer[status.next_n_index], '\n') + 1 - status.buffer;
			if (status.next_n_index == buffer_size)
			{
				free(status.buffer);
				status.buffer = NULL;
			}
			tmp = ft_strchr(ans, '\n') + 1;//今回のためにansを整理
			*tmp = '\0';//今回のためにansを整理
			return (ans);
		}
		if (status.buffer[status.next_n_index] == '\0')
		{
			free(status.buffer);
			free(ans);
			return (NULL);
		}
		free (status.buffer);
		status.buffer = NULL;
	}
	free(status.buffer);
	status.buffer = NULL;
	free(ans);
	ans = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	return (get_next_line_core(fd, BUFFER_SIZE));
}


