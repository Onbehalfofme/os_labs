#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  FILE** outputs = malloc(argc* sizeof(FILE*));
  int count = 0;
  if (strcmp(argv[1], "-a") == 0) {
    for(int i = 0; i < argc - 2; i++){
      count++;
      outputs[i] = fopen(argv[i+2], "a");
    }
  }
  else{
    for(int i = 0; i < argc - 1; i++){
      count++;
      outputs[i] = fopen(argv[i+1], "w");
    }
  }
  char buf;
  while(read(0, &buf, 1)>0){
    write(1, &buf, 1);
     for (int i = 0; i < count; i++){
        write(fileno(outputs[i]), &buf, 1);
      }
  }
  for (int i = 0; i < count; i++){
        fclose(outputs[i]);
  }
  return 0;
}
