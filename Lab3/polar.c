// Ryan O'Halloran - CSE 20311
// Lab 3

#include <stdio.h>
#include <math.h>

#define pi M_PI

double get_x(void);
double get_y(void);
int get_quadrant(double, double);
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);

int main() {
    // declare variables
    double x, y;
    int quadrant;
    double radius;
    double angle;
    // get x and y coordinates
    x = get_x();
    y = get_y();

    // get quadrant
    quadrant = get_quadrant(x, y);

    // get radius
    radius = get_radius(x, y);

    // get angle
    angle = get_angle(x, y);

    // display info
    show_info(quadrant, radius, angle);

    return 0;
}

double get_x(void) {
    // declare x variable
    double x;
    // ask for user input
    printf("Enter x coordinate (as a double): ");
    scanf("%lf", &x);
    // return x
    return x;
}

double get_y(void) {
    // declare y variable
    double y;

    // ask for user input
    printf("Enter y coordinate (as a double): ");
    scanf("%lf", &y);

    // return y
    return y;
}

int get_quadrant(double x, double y) {
    // declare quadrant variable
    int quadrant;

    // determine quadrant
    if (x < 0) {
        if (y < 0) {
            quadrant = 3;
            return quadrant;
        }
        else {
            quadrant = 2;
            return quadrant;
        }
    }
    else {
        if (y < 0) {
            quadrant = 4;
            return quadrant;
        }
        else {
            quadrant = 1;
            return quadrant;
        }
    }   
}

double get_radius(double x, double y) {
    // declare radius variable
    double radius;

    // calculate radius
    radius = sqrt(pow(x, 2) + pow(y, 2));

    // return radius
    return radius;
}

double get_angle(double x, double y) {
    // declare angle variable
    double angle;

    // calculate angle
    angle = atan2(y, x);
    angle *= 180 / pi;

    // if point is in quadrants 3 or 4, adds 360 to make all angles come from +x axis
    if (angle < 0) {
        angle += 360;
    }

    // return angle
    return angle;
}

void show_info(int quadrant, double radius, double angle) {
    // Display quadrant
    printf("The points entered are in quadrant %d.\n", quadrant);

    // Display polar coordinates
    printf("And have radius %.2lf and are %.2lf degrees counterclockwise from the positive x-axis.\n",
                     radius, angle);
}