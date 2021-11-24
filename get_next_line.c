#include "get_next_line.h"

int	file_read(t_gnl_status *status, t_gnl_status_non_static *status_non_static)
{
	ssize_t	rc;

	if (status->buffer == NULL)
	{
		status->next_n_index = 0;
		status->buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (status->buffer == NULL)
			return (-1);
		rc = read(status_non_static->fd, status->buffer, BUFFER_SIZE);
		if (rc <= 0)
		{
			free(status->buffer);
			status->buffer = NULL;
			if (rc == 0)
				return (0);
			return (-1);
		}
		status->buffer[rc] = '\0';
	}
	return (1);
}

int	organizer(t_gnl_status *status, t_gnl_status_non_static *status_non_static)
{
	char					*tmp;

	if (ft_strchr(&status->buffer[status->next_n_index], '\n'))
	{
		status->next_n_index = ft_strchr(&status->buffer[status->next_n_index], '\n') + 1 - status->buffer;
		if (status->next_n_index == BUFFER_SIZE)
		{
			free(status->buffer);
			status->buffer = NULL;
		}
		tmp = ft_strchr(status_non_static->ans, '\n') + 1;
		*tmp = '\0';
		return (0);
	}
	if (status->buffer[status->next_n_index] == '\0') 
	{	
		free(status->buffer);
		free(status_non_static->ans);
		status_non_static->ans = NULL;
		return (0);
	}
	return (1);
}

int	loop_handler(t_gnl_status *status, t_gnl_status_non_static *status_non_static)
{
	int		ret;
	char	*tmp;

	ret = file_read(status, status_non_static);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (0);
	if (status_non_static->ans == NULL)
		status_non_static->ans = ft_strdup("");
	tmp = ft_strjoin(status_non_static->ans, &status->buffer[status->next_n_index]);
	if (tmp == NULL)
		return (-1);
	free(status_non_static->ans);
	status_non_static->ans = tmp;
	ret = organizer(status, status_non_static);
	if (ret == 0)
		return (0);
	free (status->buffer);
	status->buffer = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnl_status		status;
	t_gnl_status_non_static	status_non_static;
	int						ret;

	status_non_static.fd = fd;
	status_non_static.ans = NULL;
	while (true)
	{
		ret = loop_handler(&status, &status_non_static);
		if (ret < 0)
			break ;
		if (ret == 0)
			return (status_non_static.ans);
	}
	free(status.buffer);
	status.buffer = NULL;
	free(status_non_static.ans);
	status_non_static.ans = NULL;
	return (NULL);
}
