#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 3) {
        printf("The sum of %d and %d = %d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) + atoi(argv[2]));
    }
    else if (argc == 1) {
        int a,b;
        printf("Enter 2 numbers: ");
        scanf("%d %d", &a, &b);
        printf("Their sum is %d\n", a+b);
    }
    else {
        printf("Error!\n");
        return 1;
    }
}