#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    printf("1");
    int fd1 = open("ex1.txt", O_RDWR, 0);
    int fd2 = open("ex2.txt", O_RDWR, 0);
                    
    struct stat st1, st2;
    fstat(fd1, &st1);
    fstat(fd2, &st2);
    char* buffer1 = (char*) mmap(0, st1.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    char* buffer2 = (char*) mmap(0, st2.st_size, PROT_WRITE, MAP_SHARED, fd2, 0);

    memcpy(buffer2, buffer1, st2.st_size);

    munmap(buffer1, st1.st_size);
    munmap(buffer2, st1.st_size);
    close(fd1);
    close(fd2);
    return 0;
}
