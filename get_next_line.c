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

char	*get_next_line_core(int fd, size_t buffer_size)
{
	static char 	*buffer;
	static size_t	next_n_index;
	ssize_t			rc;
	char 			*ans;
	char			*next_n_ptr;
	char			*tmp;

	rc = 1;
	ans = NULL;
	while (true)
	{
		if (buffer == NULL)
		{
			buffer = (char *)calloc((size_t)buffer_size + 1,1);
			if (buffer == NULL)
				return (NULL);
			rc = read(fd, buffer, buffer_size);
			if (rc < 0)
			{
				free(buffer);
				buffer = NULL;
				return (NULL);
			}
			if (rc == 0)
			{
				free(buffer);
				buffer = NULL;
				break ;
			}
			buffer[buffer_size] = '\0';
			next_n_index = 0;
		}
		if (ans == NULL)
		{
			ans = (char *)malloc(1);
			ans[0] = '\0';
			if (ans == NULL)
			{
				free(buffer);
				buffer = NULL;
				return(NULL);
			}
		}
		tmp = ft_strjoin(ans, &buffer[next_n_index]);
		if (tmp == NULL)
		{
			free(buffer);
			buffer = NULL;
			free(ans);
			ans = NULL;
			return (NULL);
		}
		free(ans);
		ans = tmp;
		if (ft_strchr(&buffer[next_n_index], '\n'))
		{
			next_n_ptr = ft_strchr(&buffer[next_n_index], '\n') + 1;//次のためにbufferを整理
			next_n_index = next_n_ptr - buffer;
			next_n_ptr = ft_strchr(ans, '\n') + 1;//今回のためにansを整理
			*next_n_ptr = '\0';//今回のためにansを整理
			break ;
		}
		if (buffer[next_n_index] == '\0')
		{
			free(buffer);
			free(ans);
			return (NULL);
		}
		free (buffer);
		buffer = NULL;
	}
	return (ans);
}

char	*get_next_line(int fd)
{
	return (get_next_line_core(fd, BUFFER_SIZE));
}


