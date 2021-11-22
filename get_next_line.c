#include "get_next_line.h"

char	*get_next_line_core(int fd, size_t buffer_size)
{
	static char *buffer;
	static char *ans;
	ssize_t	rc;
	char	*next_n_ptr;

	rc = 1;
	ans = "";
	while (1)
	{
		if (buffer == NULL)
		{
			buffer = (char *)malloc(buffer_size + 1);
            if (!buffer)//
                return (NULL);//
			rc = read(fd, buffer, buffer_size);
			if (rc < 0)
				return (NULL);
			if (rc == 0)
				break ;
			buffer[buffer_size] = '\0';//a0
		}
		ans = ft_strjoin(ans, buffer);
        //free (buffer);//
		if (ft_strchr(buffer, '\n'))//次のためにbufferを整理する
		{
			buffer = ft_strchr(buffer, '\n') + 1;
			next_n_ptr = ft_strchr(ans, '\n') + 1;
			*next_n_ptr = '\0';
			break ;
		}
		buffer = NULL;
	}
	return (ans);
}

char	*get_next_line(int fd)
{
	//free(ans);//
    return (get_next_line_core(fd, BUFFER_SIZE));
}
