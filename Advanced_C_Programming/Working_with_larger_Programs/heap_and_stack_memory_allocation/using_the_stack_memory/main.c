#include <stdio.h>

double get_double(double mygrade)
{
    double mydouble = 0.0;

    mydouble = mygrade * 2.0;

    return mydouble;
}


int main(int argc, char *argv[])
{
    printf("The double of %f is %f", 2.34, get_double(2.34));
    return 0;

}
