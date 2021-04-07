#include <stdio.h>

int freq(int [], int, int);

int main() {
    int sum;
    int arr[] = {5, 6, 7, 1, 3, 4, 5, 6, 7, 3, 9, 3, 6, 5, 7, 8, 9, 3, 5, 6, 1, 2, 3, 1, 2, 8, 6, 5, 4, 3, 2, 8, 1, 5, 3, 7, 5, 6, 8, 
                9, 0, 7, 6, 5, 4, 3, 2, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int num = 7, n;
    n = freq(arr, size, num);
    printf("%d times\n", n);
    return 0;
}

int freq(int arr[], int size, int num) {
    int sum=0, i;
    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            sum += 1;
        }
    }

    return sum;
}