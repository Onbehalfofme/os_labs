#include <stdio.h>


int main(void) {
     char buffer[128];
     setvbuf(stdin, buffer, _IOLBF, 128);
     printf("H");
     sleep(1);
     printf("e");
     sleep(1);
     printf("l");
     sleep(1);
     printf("l");
     sleep(1);
     printf("o");
     sleep(5);
     printf("\n");
     return 0;
}
