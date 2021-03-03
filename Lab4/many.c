#include <stdio.h>

int main() {
    // take input
    int i=0;
    int counter=0;
    int userInp;
    int array[20];

    // get first value
    printf("enter a number: ");
    scanf("%d", &userInp);
    if (userInp > 0) {
        array[i] = userInp;
    }

    while (userInp < 0) {
        printf("enter a number: ");
        scanf("%d", &userInp);
        ++counter;
        ++i;
        array[i] = userInp;
    }
    
    for (i = counter -1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    
    printf("\n");
    
}