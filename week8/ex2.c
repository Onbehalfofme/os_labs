#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 10; i++) {
        int* mem = (int*) calloc(2500000, sizeof(int));
        sleep(1);
    }
}
