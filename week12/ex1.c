#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int file = open("/dev/urandom", O_RDONLY);
  unsigned char string[20];
  if(file >= 0){
    read(file, string, sizeof(string));
  }
  FILE* result = fopen("ex1.txt", "w");
  fprintf(result, "%s\n", string);
  for (int i = 0; i < 20; i++){
   fprintf(result, "%u ", string[i]);
  }
  close(file);
  fclose(result);
  return 0;
}
