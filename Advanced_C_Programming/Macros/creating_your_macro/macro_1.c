#include <stdio.h>

#define PI 3.14
#define AREA_CIRCLE(r)  ((PI)*(r)*(r))

int main(void)
{
    int area = AREA_CIRCLE(5);
    
    printf("the area of the circle is %d. \n",area);


    return 0;
}