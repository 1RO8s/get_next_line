/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/31 18:50:57 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * 先頭から最初の改行までの文字列を取り出す
 * ex) ("ABC\nDEF\nG") -> "ABC\0"
 * ex) ("ABC\0") -> "ABC\0"
 */
char	*substr_until_newline(char *buf)
{
	char	*dup;
	char	*newline;

	dup = ft_strdup(buf);
	newline = ft_strchr(dup, '\n');
	if (newline != NULL)
		*(newline + 1) = '\0';
	return (dup);
}

/**
 * 最初の改行から末尾までの文字列を取り出す
 */
char	*substr_after_newline(char *buf)
{
	char	*dup;
	char	*newline;

	dup = ft_strdup(buf);
	newline = ft_strchr(dup, '\n');
	if (newline != NULL)
	{
		return (newline + 1);
	}
	return (dup);
}

/**
 * 改行か終端がくるまで読み込み続ける
 * 読み込みに失敗したらNULLを返す
 */
char	*ft_read_to_newline(int fd, char *read_str)
{
	char	*buf;
	ssize_t	read_bytes;
	size_t	i;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (BUFFER_SIZE + 1 - i)
	{
		*(buf + i) = (unsigned char)0;
		i++;
	}
	read_bytes = BUFFER_SIZE;
	while (!ft_strchr(buf, '\n') && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			return (NULL);
		}
		buf[read_bytes] = '\0';
		read_str = ft_strjoin(read_str, buf);
	}
	free(buf);
	return (read_str);
}

#define MAX_FD 1024

char	*get_next_line(int fd)
{
	static char	*prev[MAX_FD];
	char		*read_str;
	char		*line;

	read_str = ft_read_to_newline(fd, prev[fd]);
	line = substr_until_newline(read_str);
	prev[fd] = substr_after_newline(read_str);
	return (line);
}
