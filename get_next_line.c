/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:30 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/24 15:08:09 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *buf;
    buf = (char*)malloc(sizeof(char) * BUFFER_SIZE);

    if (buf == NULL)
        printf("fail\n");

    // size_t n;
    // char *p_buf;
    // p_buf = buf;
    // n = BUFFER_SIZE;
	// while (n--)
	// 	*(p_buf++) = (unsigned char)0;

    size_t read_bytes;

    read_bytes = 0;

    printf("----\n"),
    read_bytes = read(fd, buf,42);

    return &buf[0];
}