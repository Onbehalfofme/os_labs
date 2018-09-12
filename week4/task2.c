#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
// The output will be a tree because every fork will recursevly call other fork which are below them in program
int main(){
	fork();
	fork();
	fork();
	sleep(30);
}
