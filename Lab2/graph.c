#include <stdio.h>
#include <math.h>

int main() {
    // Declare function variables
    float x, y;
    int numStars;
    float xIncrement = 0.01;
    float xStart = 4.67;
    float xRange = 6.39;
    float yMax = 0;
    float yMin = INFINITY;
    float xMax;
    float xMin;
    // Kobe
    // Print header
    printf("\nPlot for y = abs(1.5 * sin(x^2) * 2x^(-1) * e^(0.1x^(2)) from x = %.2f to x = %.2f.\n",
                     xStart, xRange);
    printf("%*s%s%*s%s\n", 2, "", "X", 8, "", "Y");

    // Main loop
    for (x = xStart; x <= xRange + xIncrement; x += xIncrement) {
        // Calculate value of y for each iteration
        y = fabs(1.5 * sin(pow(x, 2)) * 2 * pow(x, -1) * exp(0.1 * pow(x, 2)));

        // Determine min and max vals
        if (y < yMin) {
            yMin = y;
            xMin = x;
        }
        else if (y > yMax) {
            yMax = y;
            xMax = x;
        }
        // Determine number of stars to print
        numStars = y * 3;
        // Print values
        printf("%5.2f", x);
        printf("%*s", 4, "");
        printf("%5.2f  ", y);
        // Loop across range and print stars
        for (int i = 0; i <= numStars; i++) {
            printf("*");
        }
        printf("\n");
    }
    // Print max and min x and y values
    printf("\nThe maximum of %.2f was at %.2f.\n", yMax, xMax);
    printf("The minimum of %.2f was at %.2f.\n", yMin, xMin);

    return 0;
}
