#include <stdio.h>

#define TWO_PI 2.0 * 3.1415
const float two_pi=6.28;


int main(void)
{
    float circumference_circle = TWO_PI * 6;
    printf("The circumference of the circle with radius of 6cm is %f .\n", circumference_circle);

    printf("The value of the constant is %f.\n", two_pi);


    return 0;
}