#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char s1[256], s2[256];
	int fd[2];
	scanf("%s", s1);
	pipe(fd);
	
	write(fd[1], s1, 256);
	close(fd[1]);

	read(fd[0], s2, 256);
	close(fd[0]);

	printf("%s\n", s2);
	return 0;
}
