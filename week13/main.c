#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE* file = fopen("input_dl.txt", "r");
  FILE* out1 = fopen("output_dl.txt", "w");
  FILE* out2 = fopen("output_ok.txt", "w");
  char line[128];
  int e[30];
  int a[30];
  fgets(line, 128, file);
  int number = line[0] - '0';
  int counter = 0;
  for (int i = 1; i < strlen(line)-1; i++){
    if(line[i] == ' '){
      e[counter++] = number;
      number = line[++i]-'0';    
    }
    else{
        number = 10*number + (line[i] - '0');
    }
    if(i == strlen(line) - 2){
      e[counter] = number;
    }
  }
  fgets(line, 128, file);
  fgets(line, 128, file);
  number = line[0] - '0';
  counter = 0;
  for (int i = 1; i < strlen(line)-1; i++){
    if(line[i] == ' '){
      a[counter++] = number;
      number = line[++i]-'0';
    }
    else{
        number = 10*number + (line[i] - '0');
    }
    if(i == strlen(line) - 2){
      a[counter] = number;
    }
  }
  fgets(line, 128, file);
  int size = counter;
  int c[30][counter];
  int r[30][counter];
  int current = 0;
  while(strcmp(fgets(line, 128, file), "\n") != 0){
    number = line[0] - '0';
    counter = 0;
    for (int i = 1; i < strlen(line)-1; i++){
      if(line[i] == ' '){
        c[current][counter++] = number;
        number = line[++i]-'0';
      }
      else{
          number = 10*number + (line[i] - '0');
      }
    }
    c[current++][counter] = number;
  }
  current = 0;
  while(fgets(line, 128, file)  != NULL){
    number = line[0] - '0';
    counter = 0;
    for (int i = 1; i < strlen(line)-1; i++){
      if(line[i] == ' '){
        r[current][counter++] = number;
        number = line[++i]-'0';
      }
      else{
          number = 10*number + (line[i] - '0');
      }
    }
     r[current++][counter] = number;
  }
  int changed = 0;
  int zerolines = 0;
  int *zerolined = calloc(current, sizeof(int));
  while(1){
    changed = 0;
    for (int i = 0; i < current; i++){
      int enough = 1;
      for (int j = 0; j < size; j++){
        if(r[i][j] > a[j]){
          enough = 0;
        }
        printf("%d %d\n",i,enough);
        if (enough){
          changed = 1;
          for (int k = 0; k < size; k++){
            a[k] += c[i][k];
            c[i][k] = 0;
            r[i][k] = 0;
          }
          if(zerolined[i] == 0){
            zerolines++;
            zerolined[i]++;
            //printf("%d ",i);
          }
        }
      }
    }
    if (!changed){
      if(zerolines == current){
        fprintf(out2,"There is no deadlocks!");
      }
      else{
        fprintf(, out1,"I found %d deadlocked processes", current - zerolines);
      }
      break;
    }
  }

  fclose(file);
  fclose(out1);
  fclose(out2);
  return 0;
}