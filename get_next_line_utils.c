#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	total_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof (char) * (total_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j ++;
	}
	result[i + j] = '\0';
	return (result);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i ++;
		return (i);
	}
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	while (src[i])
		i ++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	ptr = (char *) malloc (sizeof (*s1) * (len + 1));
	if (!ptr)
		return (NULL);
	else
		ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}
