#include <stdio.h>
#include <malloc.h>

double simulation(const int *pageNumbers, int frameNumber, int counter) {
    int hit = 0;
    int miss = 0;
    int *frame = (int *) calloc((size_t) frameNumber, sizeof(int));
    int *pages = (int *) calloc(1000, sizeof(int));
    for (int i = 0; i < 1000; i++) {
        pages[i] = 1;
    }
    for (int i = 0; i < counter; ++i) {
        for (int k = 0; k < frameNumber; ++k) {
            pages[frame[k]] = pages[frame[k]] >> 1;
        }
        int hitted = 0;
        int index = 0;
        for (int j = 0; j < frameNumber; ++j) {
            if (frame[j] == pageNumbers[i]) {
                hitted = 1;
                index = j;
                break;
            }
        }
        if (hitted) {
            pages[frame[index]] += (1 << 31);
            hit++;
        } else {
            int empty = 0;
            for (int k = 0; k < frameNumber; ++k) {
                if (frame[k] == 0) {
                    frame[k] = pageNumbers[i];
                    pages[frame[k]] = 1 << 31;
                    empty = 1;
                    break;
                }
            }
            if (!empty) {
                int i1 = 0;
                int min = pages[frame[0]];
                for (int k = 1; k < frameNumber; ++k) {
                    if (pages[frame[k]] < min) {
                        min = pages[frame[k]];
                        i1 = k;
                    }
                }
                frame[i1] = pageNumbers[i];
                pages[frame[i1]] = 1 << 31;
            }
            miss++;
        }
    }
    return (double)hit / miss;
}

int main() {
    FILE *file = fopen("C:\\Users\\ak474\\CLionProjects\\untitled2\\input.txt", "r");
    int counter = 0;
    int num;
    do {
        fscanf(file, "%d", &num);
        counter++;
    } while (fgetc(file) != EOF);
    fclose(file);
    int *pages = (int *) malloc(counter * sizeof(int));
    counter = 0;
    file = fopen("C:\\Users\\ak474\\CLionProjects\\untitled2\\input.txt", "r");
    do {
        fscanf(file, "%d", &pages[counter++]);
    } while (fgetc(file) != -1);
    fclose(file);
    printf("%f\n", simulation(pages, 10, counter));
    printf("%f\n", simulation(pages, 50, counter));
    printf("%f\n", simulation(pages, 100, counter));
    return 0;
}