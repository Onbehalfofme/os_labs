#include <stdio.h>
#include <stdlib.h>


int main(){
	char command[10];
        while (1){
	        printf("> ");
	        fgets(command, 10, stdin);
	        system(command);
		return 0;
	}
}
