#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t cpid = fork();
    if(cpid == 0) {
        while(1){
            printf("I'm alive\n");
            sleep(1);
            exit(EXIT_SUCCESS);
        }
    }
    else{
        sleep(10);
        kill(cpid, SIGTERM);
        exit(EXIT_SUCCESS);
    }
    return 0;
}
