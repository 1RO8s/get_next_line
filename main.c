/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:33:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/27 23:21:56 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	const char	*result;
	char		ch;

	ch = (char)c;
	result = s;
	size_t i = 0;
	while (*result != '\0')
	{
		if (*result == ch)
			return ((char *)result);
		result++;
		i++;
	}
	if (*result == '\0' && *result == ch)
		return ((char *)result);
	return (NULL);
}

/**
 * 改行が見つかったらそのアドレス。見つからない場合は、
 */
char	*get_line_end(char *buf)
{
	char	*line_end;
	char	*eof;

	// buf[BUFFER_SIZE] = '\n';
	printf("\nget_line_end: buf[%d]:%c(%d) buf:%s\n",BUFFER_SIZE,buf[BUFFER_SIZE],buf[BUFFER_SIZE],buf);
	line_end = ft_strchr(buf, '\n');
	eof = ft_strchr(buf, '\0');
	if (line_end != NULL)
	{
		printf("    return line end:%d(%p)\n",*line_end,line_end);
		*line_end = '\0';
		return (line_end);
	}
	else if (eof != NULL)
	{
		printf("    return eof:%d(%p) %ld\n",*eof,eof, eof-buf);
		*eof = '\0';
		return (eof);
	}
	else
	{
		buf[BUFFER_SIZE] = '\n';
		printf("    return buffer size:%c(%p)\n",buf[BUFFER_SIZE],&buf[BUFFER_SIZE]);
		return (&buf[BUFFER_SIZE]);
	}
}

int	main(void)
{
	int		fd;
	char	*buf;
	ssize_t	read_bytes;
	char	*line_end;

	fd = open("./testfiles/file002", O_RDONLY);
	// printf("fd:%d\n",fd);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		printf("malloc fail\n"); 
	buf[BUFFER_SIZE] = '\n';
	read_bytes = read(fd, buf, BUFFER_SIZE);
	line_end = get_line_end(buf);
	// read_bytes = line_end - buf;
	// printf("\n1 buf[read_bytes]:%d read_bytes %ld", buf[20], read_bytes);
	printf("\nline:%s\n", buf);
	printf("\n----------\n");
	read_bytes = read(fd, buf, BUFFER_SIZE);
	line_end = get_line_end(buf);
	// read_bytes = line_end - buf;
	// printf("\n2 buf[read_bytes]:%d read_bytes %ld", buf[20], read_bytes);
	printf("\nline:%s\n", buf);
}
