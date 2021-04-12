#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFSIZE 512
/* 파일 크기를 계산 한다 */
int main(int argc, char *argv[]) 
{
	char buffer[BUFSIZE];
	int fd;
	ssize_t nread;
	long total = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1) 
		perror(argv[1]);
	/* 파일의 끝에 도달할 때까지 반복해서 읽으면서 파일 크기 계산 */
	while( (nread = read(fd, buffer, BUFSIZE)) > 0)
		total += nread;
	close(fd);
	printf ("%s 파일 크기 : %ld, fd = %d\n", argv[1], total, fd);
	exit(0);
}
