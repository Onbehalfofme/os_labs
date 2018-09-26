#include"signal.h"
#include"stdio.h"
#include"unistd.h"
#include"stdlib.h"
// The output is handler for  SIGUSR1 since we send SIGUSR1 signall in shell when kill the process
void killHandler(){
    printf("\nSIGKILL\n");
    exit(1);
}

void stopHandler(){
        printf("\nSIGSTOP\n");
            exit(1);
}

void usrHandler(){
        printf("\nSIGUSR1\n");
            exit(1);
}
int main()
{
    signal(SIGKILL, killHandler);
    signal(SIGSTOP, stopHandler);
    signal(SIGUSR1, usrHandler);
    while(1){}
    return 0;
}
