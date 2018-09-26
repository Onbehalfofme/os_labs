#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<signal.h>

void stopHandler(){
    printf("You stopped me, brother\n");
}

int main() {
    int fd[2];
    pid_t cpid[2];
    pipe(fd);
    cpid[0]  = fork();
    signal(SIGSTOP, stopHandler);
    if (cpid[0] == 0){
        printf("I'm a first child. Be afraid of me\n");
        pid_t sibling;
        read(fd[0], &sibling, sizeof(pid_t));
        close(fd[0]);
        close(fd[1]);
        printf("I know your IP, bro");
        sleep(6);
        kill(sibling, SIGSTOP);
        printf("I stopped you, bro");
        sleep(6);
        exit(EXIT_SUCCESS);
    }
    else{
        cpid[1] = fork();
        
        if (cpid[1] == 0){
            printf("I'm second");
            write(fd[1], getpid(), sizeof(pid_t));
            close(fd[1]);
            close(fd[0]);
        }
        else{
            write(fd[1], &cpid[1], sizeof(pid_t));
            close(fd[1]);
            close(fd[0]);
            int code;
            pid_t c = waitpid(cpid[1], &code, 0);
            printf("Second child is over. In the end he said %d", code);
        }
    }
    return 0;
}       
