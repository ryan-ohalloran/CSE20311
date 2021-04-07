#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = 1; i <= n-1; i++) {
        for (j = n-1; j >= i; j--) {
            printf("%d ", n-j);
        }
        printf("\n");
    }

    return 0;
}