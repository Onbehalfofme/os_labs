#include"signal.h"
#include"stdio.h"
#include"unistd.h"
#include"stdlib.h"

void handler(){
    printf("\nProccess has been terminated by user. (CTRL-C)\n");
    exit(1);
}
int main()
{
    signal(SIGINT, handler);
    while(1){}
    return 0;
}
