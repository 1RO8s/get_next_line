/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/23 16:43:44 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	const char	*result;
	char		ch;

	ch = (char)c;
	result = s;
	while (*result != '\0')
	{
		if (*result == ch)
			return ((char *)result);
		result++;
	}
	if (*result == '\0' && *result == ch)
		return ((char *)result);
	return (NULL);
}

char	*free_return(char *p, char *res)
{
	free(p);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*(p++) = (unsigned char)0;
}

/**
 * Keep reading until a newline or the end of the line.
 * Returns NULL if reading fails.
 */
static char	*ft_read_to_newline(int fd, char *read_str)
{
	char	*buf;
	char	*read_str_old;
	ssize_t	read_bytes;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, sizeof(char) * BUFFER_SIZE + 1);
	read_bytes = 1;
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_return(buf, NULL));
		buf[read_bytes] = '\0';
		read_str_old = read_str;
		read_str = ft_strjoin(read_str_old, buf);
		free(read_str_old);
	}
	free(buf);
	if (read_str[0] == 0)
		return (free_return(read_str, NULL));
	return (read_str);
}

char	*get_next_line(int fd)
{
	static char	*prev[MAX_FD];
	char		*read_str;
	char		*line;
	char		*newline;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	read_str = ft_read_to_newline(fd, prev[fd]);
	if (!read_str)
		return (NULL);
	line = ft_strdup(read_str);
	if (line == NULL)
		return (free_return(line, NULL));
	free(read_str);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		prev[fd] = ft_strdup(newline + 1);
		if (prev[fd] == NULL)
			return (free_return(line, NULL));
		*(newline + 1) = '\0';
	}
	else
		prev[fd] = NULL;
	return (line);
}
