/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:33:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/05/24 14:16:06 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int fd = open("./testfiles/file002",O_RDONLY);
    printf("fd:%d\n",fd);

    char buf[BUFFER_SIZE];

    for(int i=0; i < BUFFER_SIZE;i++){
        printf("i:%d %c(%d)\n",i,buf[i],buf[i]);
    }
    
    size_t read_bytes = read(fd, &buf,BUFFER_SIZE);

    printf("read_bytes:%ld\n",read_bytes);
    for(int i=0;buf[i] != '\0';i++){
        printf("i:%d %c(%d)\t",i,buf[i],buf[i]);
    }
    buf[read_bytes] = '\0';
    printf("\nread line:[%s]\n",buf);    
}
