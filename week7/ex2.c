#include"stdlib.h"
#include"stdio.h"

int main() {
    int x;
    printf("Enter the size of array\n");
    scanf("%d", &x);
    int *a = (int *) calloc(x, sizeof(int));
    for (int i = 0; i < x; i++){
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}
