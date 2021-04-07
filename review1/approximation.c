#include <stdio.h>
#include <math.h>

double myfunc(double);

int main() {
    double y;
    double x = 0.399;
    y = myfunc(x);
    printf("Final value: %lf\n", y);
}

double myfunc(double x) {
    int i;
    double approx=0;
    for (i=0; i<=INFINITY; i++) {
        if (pow(x, i) <= 0.001) {
            break;
        }
        else {
            approx += pow(x, i);
        }
    }

    return approx;
}