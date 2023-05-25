/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/25 22:46:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*has_next_line(char *buf)
{
	while (*buf != '\0')
	{
		if (*buf == '\n')
		{
			return (buf);
		}
	}
    return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buf;
	size_t		read_bytes;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		printf("fail\n");
	// size_t n;
	// char *p_buf;
	// p_buf = buf;
	// n = BUFFER_SIZE;
	// while (n--)
	// 	*(p_buf++) = (unsigned char);
	read_bytes = 0;
	read_bytes = read(fd, buf, BUFFER_SIZE);
	printf("read_bytes:%ld\n", read_bytes);
	while (!has_next_line(buf))
	{

		read_bytes += read(fd, buf, BUFFER_SIZE);
	}
	//
	// printf("end:%c\n",buf[read_bytes-2]);
	// printf("end:%c\n",buf[read_bytes-1]);
	// printf("end:%d\n",buf[read_bytes]);
	// printf("end:%d\n",buf[read_bytes+1]);
	// printf("end:%d\n",buf[read_bytes+2]);
	return (&buf[0]);
}

//
// 改行だけの行は'\0'を返す

// abcdefg\n\nhijklmno\npqrstu\n\0