/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/28 21:19:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


/**
 * 先頭から最初の改行までの文字列を取り出す
 * ex) ("ABC\nDEF\nG") -> "ABC\0"
 * ex) ("ABC\0") -> "ABC\0"
 */
char *substr_until_newline(char *buf)
{
	char *dup;
	char *line_end;
	dup = ft_strdup(buf);
	line_end = ft_strchr(dup,'\n');
	
	if(line_end != NULL){
		line_end = '\0'; // 改行が見つかったら終端文字に置き換える
	}
	return dup;
}

/**
 * 最初の改行から末尾までの文字列を取り出す
 */
char *substr_after_newline(char *buf)
{
	char *dup;
	char *line_end;
	dup = ft_strdup(buf);
	line_end = ft_strchr(dup,'\n');
	

	if(line_end != NULL){
		line_end = '\0';
		return line_end + 1; // 改行の次のアドレスを返す
	}
	return dup;
}

char	*get_next_line(int fd)
{
	static char	*remaining_str;
	char		*buf;
	ssize_t		read_bytes;
	int is_eof_reached;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		printf("fail\n");

	read_bytes = 0;
	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
	if(BUFFER_SIZE < read_bytes)
		is_eof_reached = TRUE;

	char *line = substr_until_newline(buf); // 改行までの文字列を取り出す
	char *remaining_str = substr_after_newline(buf);



	//
	// printf("end:%c\n",buf[read_bytes-2]);
	// printf("end:%c\n",buf[read_bytes-1]);
	// printf("end:%d\n",buf[read_bytes]);
	// printf("end:%d\n",buf[read_bytes+1]);
	// printf("end:%d\n",buf[read_bytes+2]);
	return (&buf[0]);
}

