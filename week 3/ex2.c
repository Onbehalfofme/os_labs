#include <stdio.h>

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size / sizeof(arr) - 1; i++) {
        for (int j = i + 1; j < size / sizeof(int); j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(arr, sizeof(arr));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { printf("%d\n", arr[i]); }
    return 0;
}