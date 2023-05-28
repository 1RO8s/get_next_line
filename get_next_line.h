/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:20:10 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/28 21:18:20 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#ifndef GNL_H
#define GNL_H

#define TRUE 1
#define FALSE 0

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
char	*ft_strdup(const char *s1)
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
char	*ft_strjoin(char const *s1, char const *s2)
char *get_next_line(int fd);

#endif