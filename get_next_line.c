/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/16 09:50:41 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void *show_malloc_address(size_t size, const char *file, unsigned int line)
{
	void *p;
	p = malloc(size);
	printf("\n## %s[%d]: malloc(%p)\n",file,line,p);
	return p;
}


static void show_free_address(void *p, const char *file, unsigned int line)
{
	free(p);
	printf("\n## %s[%d]: free(%p)\n",file,line,p);
}

#define malloc(s) show_malloc_address(s, __FILE__, __LINE__) 
#define free(s) show_free_address(s, __FILE__, __LINE__) 

/////

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
 * 先頭から最初の改行までの文字列を取り出す
 * ex) ("ABC\nDEF\nG") -> "ABC\0"
 * ex) ("ABC\0") -> "ABC\0"
 */
static char	*substr_until_newline(char *buf)
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
static char	*substr_after_newline(char *buf)
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
static char	*ft_read_to_newline(int fd, char *read_str)
{
	printf("read_to_newline\n");
	char	*buf;
	ssize_t	read_bytes;
	size_t	i;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		*(buf + i) = (unsigned char)0;
		i++;
	}
	read_bytes = 1;
	while (!ft_strchr(buf, '\n') && read_bytes != 0)// 改行か終端がくるまでread
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		// printf("read_str:%s \n",read_str);
		// printf("read_bytes:%zu \n",read_bytes);
		// printf("buf:%s",buf);
		if (read_bytes == -1)
		{
			printf("fail file read\n");
			free(buf);
			return (NULL);
		}
		if (read_bytes == 0){
			printf("return 0 by read\n");
		// 	free(buf);
		// 	return (NULL);
		}
		buf[read_bytes] = '\0';
		read_str = ft_strjoin(read_str, buf);
	}
	// printf("2. read_str:%s \n",read_str);
	// printf("2. buf:%s",buf);
	free(buf);
	if (read_str[0] == 0)
		return (NULL);
	return (read_str);
}




#define MAX_FD 1024

char	*get_next_line(int fd)
{
	static char	*prev[MAX_FD];
	char		*read_str;
	char		*line;

	// printf("pre:%s",prev[fd]);

	// if (fd < 0 || BUFFER_SIZE <= 0)
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	read_str = ft_read_to_newline(fd, prev[fd]);
	if (!read_str)
		return (NULL);
	line = substr_until_newline(read_str);
	prev[fd] = substr_after_newline(read_str);
	printf("line(%p)\n",line);
	free(read_str);
	return (line);
}
