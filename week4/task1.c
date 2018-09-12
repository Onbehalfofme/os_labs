#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
//such input occurs because all commands after fork are executed twice by parent and child proccess
int main(){
	pid_t n;
	printf("Hello from parent PID = %d\n",  getpid());
	fork();
        printf("Hello from children PID = %d\n", getpid());
	return 0;
}
