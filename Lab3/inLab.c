#include <stdio.h>

// function prototypes go here
int find_perim(float, float);
int find_area(float, float);
int display(float, float);

int main()
{
  float len, wid;
  float perim, area;

  printf("enter the length: ");
  scanf("%f", &len);
  printf("enter the width: ");
  scanf("%f", &wid);

  perim = find_perim(len, wid);  // call the find_perim function
  area = find_area(len, wid);    // call the find_area function

  display(perim, area);          // call the display function

  return 0;
}

// function definitions go here ...
    int find_perim(float len, float wid) {
        return 2 * (len + wid);
    }

    int find_area(float len, float wid) {
        return len * wid;
    }

    int display(float perim, float area) {
        printf("the perimeter is: %.2f\n", perim);
        printf("the area is: %.2f\n", area);
        return 0;
    }
