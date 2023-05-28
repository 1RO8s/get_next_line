
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void sample1(){
	int		fd;
	char	*buf;
	size_t	read_bytes;

	fd = open("./testfiles/sample01", O_RDONLY);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		printf("malloc fail\n");

	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
    printf("buf1: read_bytes=%ld %s\n",read_bytes,buf);

	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
    printf("buf2: read_bytes=%ld %s\n",read_bytes,buf);
	
	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
    printf("buf3: read_bytes=%ld %s\n",read_bytes,buf);

	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
    printf("buf4: read_bytes=%ld %s\n",read_bytes,buf);

	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
    printf("buf5: read_bytes=%ld %s\n",read_bytes,buf);
}

int	main(void)
{
	sample1();
}