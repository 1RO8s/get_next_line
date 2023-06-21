/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/21 16:43:11 by hnagasak         ###   ########.fr       */
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

/**
 * 最初の改行から末尾までの文字列を取り出す
 * 改行が見つからない場合はNULLを返す
 */
// static char	*substr_after_newline(char *buf)
// {
// 	char	*dup;
// 	char	*newline;

// 	dup = ft_strdup(buf);
// 	newline = ft_strchr(dup, '\n');
// 	if (newline != NULL)
// 	{
// 		free(dup);
// 		return (newline + 1);
// 	}
// 	free(dup);
// 	return (NULL);
// }

int	check(ssize_t rb, char *buf)
{
	if (rb == -1)
	{
		free(buf);
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*(p++) = (unsigned char)0;
}

/**
 * 改行か終端がくるまで読み込み続ける
 * 読み込みに失敗したらNULLを返す
 */
static char	*ft_read_to_newline(int fd, char *read_str)
{
	char	*buf;
	char	*read_str_old;
	ssize_t	read_bytes;

	printf("## call ft_read_to_newline\n");
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	printf("## call 1\n");
	if (buf == NULL)
		return (NULL);
	printf("## call 2\n");
	ft_bzero(buf,sizeof(char) * BUFFER_SIZE + 1);
	read_bytes = 1;
	printf("## buf:%s, read_bytes:%ld\n", buf, read_bytes);
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
	{
		printf("## call read\n");
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (check(read_bytes, buf))
			return (NULL);
		buf[read_bytes] = '\0';
		read_str_old = read_str;
		read_str = ft_strjoin(read_str_old, buf);
		free(read_str_old);
	}
	free(buf);
	printf("## call 3\n");
	if (read_str[0] == 0)
	{
		printf("## call 4\n");
		free(read_str);
		return (NULL);
	}
	printf("## call 5\n");
	return (read_str);
}

#define MAX_FD 1024

char	*get_previous(char *newline)
{
	if (*(newline + 1) == '\n')
		return (NULL);
	else
		return (ft_strdup(newline + 1));
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
	printf("## call 55 read_str:%s\n",read_str);
	if (!read_str)
	{
		printf("## call 56\n");
		free(read_str);
		return (NULL);
	}
	printf("## call 6\n");
	line = ft_strdup(read_str);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		prev[fd] = get_previous(newline);
		*(newline + 1) = '\0';
	}
	else
		prev[fd] = NULL;
	free(read_str);
	printf("line:%s\n", line);
	printf("prev[%d]:%s\n", fd, prev[fd]);
	return (line);
}
