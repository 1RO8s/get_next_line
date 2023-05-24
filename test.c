/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:33:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/24 15:12:05 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(){
    int fd = open("./testfiles/file002",O_RDONLY);
    printf("fd:%d\n",fd);

    char *line = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    if (line == NULL)
        printf("fail allocate line\n");

    line = get_next_line(fd);
    printf("line:%s",line);

    line = get_next_line(fd);
    printf("line:%s",line);

}



