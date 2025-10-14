#include <stdio.h>

int main(void)
{
    char my_char = '\n';

    my_char = getc(stdin);
    printf("%c",my_char);

    return 0;
}