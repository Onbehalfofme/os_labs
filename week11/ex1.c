#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char* str = "This is a nice day";
    int fd = open("ex1.txt", O_RDWR, 0);
    struct stat st;
    fstat(fd, &st);
    char* buffer = (char*) mmap(0, strlen(str)+1, PROT_WRITE, MAP_SHARED, fd, 0);
               
    memcpy(buffer, str, strlen(str));
    for (int i = strlen(str);i < st.st_size; i++){
        buffer[i] = ' ';
    } 

    
    munmap(buffer, strlen(str));
    close(fd);
    return 0;
}
