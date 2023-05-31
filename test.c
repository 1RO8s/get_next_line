/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:33:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/31 19:11:49 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void read_single_file()
{
    int fd = open("./testfiles/file002", O_RDONLY);
    printf("fd:%d\n", fd);

    char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (line == NULL)
        printf("fail allocate memories\n");

    for (int i = 0; i < 5; i++)
    {
        line = get_next_line(fd);
        printf("line %d:%s", i + 1, line);
    }
    close(fd);
}

void read_multiple_file()
{
    int fd[3];

    char *file_paths[3] = {
        "./testfiles/file001",
        "./testfiles/file002",
        "./testfiles/file003"};

    // 複数ファイルopen
    for (int i = 0; i < 3; i++)
    {
        fd[i] = open(file_paths[i], O_RDONLY);
        printf("fd[%d]:%d\n", i, fd[i]);
    }

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 3 ;i++)
        {
            char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
            if (line == NULL)
                printf("fail allocate memories\n");
            line = get_next_line(fd[i]);
            printf("fd[%d] line %d:%s", i, j + 1, line);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        close(fd[i]);
    }
}

int main()
{
    read_multiple_file();
}
