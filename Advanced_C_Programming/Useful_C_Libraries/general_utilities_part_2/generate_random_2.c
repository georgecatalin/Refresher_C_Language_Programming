#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));

    for (size_t i = 0; i < 30; i++)
    {
       printf("The number generated is %d .\n", rand() %10 +1 ); // 1...10
    }
    


    return 0;
}