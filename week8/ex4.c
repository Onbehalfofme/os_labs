#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    for (int i = 0; i < 10; i++) {
        int* mem = (int*) calloc(2500000, sizeof(int));
        struct rusage use;
        getrusage(RUSAGE_SELF, &use);
        printf("Maximum resident site size: %ld\nPage reclaims: %ld\n Page faults: %ld\nSwaps: %ld\n\n", use.ru_maxrss, use.ru_minflt, use.ru_majflt, use.ru_nswap);
        sleep(1);
    }
}
