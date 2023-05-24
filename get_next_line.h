/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:20:10 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/24 14:54:18 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif