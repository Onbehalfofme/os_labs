#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
        char s1[256], s2[256];
        int fd[2];
        
        scanf("%s", s1);
        pipe(fd);

        pid_t cpid = fork();
        if (cpid == 0){
            read(fd[0], s2, 256);
            printf("%s",s2);
            close(fd[0]);
            close(fd[1]);
            exit(EXIT_SUCCESS);
        }
        else{
            close(fd[0]);
            write(fd[1], s1, 256);
            close(fd[1]);
            wait(NULL);
            exit(EXIT_SUCCESS);
        }
        

        printf("%s\n", s2);
        return 0;
}
