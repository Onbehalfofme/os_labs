#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main(){
	char command[30];
	system("man fork");
	system("man execve");
       	while (1){
	    printf("> ");
	    fgets(command, 30, stdin);
	    system(command);
	}
}
