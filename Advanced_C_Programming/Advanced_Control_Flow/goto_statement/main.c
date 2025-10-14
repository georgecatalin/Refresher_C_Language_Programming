#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned int counter_max = 5;
    int counter;
    int number = 0;

    float sum = 0.0f, average = 0.0f;

    for(counter = 1; counter <= counter_max; counter++)
    {
        printf("Enter your number, please:");
        scanf("%i", &number);

        if (number < 0)
        {
            goto mylabel;
        }

        sum += number;
    }

      mylabel:
        printf("The sum is %f.\n",sum);
        average = sum/(counter-1);
        printf("The average is %f.\n",average);

    return 0;
}