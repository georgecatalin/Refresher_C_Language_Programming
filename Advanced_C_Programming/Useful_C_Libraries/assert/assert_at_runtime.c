#include <stdio.h>
#include <assert.h>

#undef NDEBUG  // Use preprocessor directive NDEBUG to disable assert() when defined in the file

int main(void)
{
    int y = 5;

    for (int x = 0; x < 10; x++)
    {
        printf("The value of x is %d and y is %d.\n", x,y);
        assert(x < y);
    }
    
    return 0;
}