/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:33:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/15 11:46:55 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void read_single_file()
{
    printf("\n----- single file -----\n");
    int fd = open("./testfiles/file002", O_RDONLY);
    printf("fd:%d\n", fd);

    char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (line == NULL)
        printf("fail allocate memories\n");

    for (int i = 0; i < 2; i++)
    {
        line = get_next_line(fd);
        printf("line %d:%s", i + 1, line);
    }
    close(fd);
}

void read_multiple_file()
{
    printf("\n----- multiple file -----\n");
    int fd[3];

    char *file_paths[3] = {
        "./testfiles/file001",
        "./testfiles/file002",
        "./testfiles/file003"};

    // 複数ファイルopen
    for (int i = 0; i < 3; i++)
    {
        fd[i] = open(file_paths[i], O_RDONLY);
        printf("fd[%d]:%d ", i, fd[i]);
    }
    printf("\n");

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
            if (line == NULL)
                printf("fail allocate memories\n");
            line = get_next_line(fd[i]);
            printf("%s line %d:%s", file_paths[i], j + 1, line);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        close(fd[i]);
    }
}

char *Bool(int a){
	if (a == 0)
		return "False";
	else
		return "True";
}

void read_empty_file()
{
    printf("\n----- empty file -----\n");
    int fd = open("./testfiles/empty", O_RDONLY);
    printf("fd:%d\n", fd);

    char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (line == NULL)
        printf("fail allocate memories\n");
    line = get_next_line(fd);
    printf("line == NULL:%s\n",Bool(line == NULL));
    printf("line :%s", line);
    // printf("line %d:%d", i + 1, *line);
    close(fd);
}

void read_newline()
{
    printf("\n----- newline -----\n");
    int fd = open("./testfiles/newline", O_RDONLY);
    printf("fd:%d\n", fd);

    char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (line == NULL)
        printf("fail allocate memories\n");

    for (int i = 0; i < 3; i++)
    {
        line = get_next_line(fd);
        // printf("line == NULL:%d\n",line == NULL);
        printf("line %d:%d", i + 1, *line);
    }
    close(fd);
}

int main()
{
    read_single_file();
    read_empty_file();
    // read_multiple_file();
    // read_newline();
}
