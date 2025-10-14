#include <stdio.h>


/*
size_t in C:

Definition:

- Unsigned integer type returned by sizeof and used for object sizes and array indices.
- Typedef from the implementation, big enough to represent the maximum size of any object in that platform.
- Declared in: <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <wchar.h>, etc

Why unsigned:

 - Sizes and counts cannot be negative.
-  Gives you one more bit of positive range vs a signed type of same width.

Typical underlying types:

- 32‑bit systems: unsigned int or unsigned long (32 bits).
- 64‑bit systems: usually unsigned long (Linux) or unsigned long long / unsigned __int64 (some Windows ABIs).


The size of size_t is implementation-defined and tied to the data model / addressable memory range, not strictly the OS or
 CPU bitness.

Common data models and typical sizeof(size_t):
- 16-bit (obsolete / small embedded, LP32 style): 2 bytes (SIZE_MAX = 0xFFFF)
- ILP32 (most 32-bit desktop/embedded): 4 bytes (SIZE_MAX = 0xFFFFFFFF)
- LP64 (Unix-like 64-bit: Linux, macOS, BSD on x86_64/aarch64): 8 bytes (SIZE_MAX = 0xFFFFFFFFFFFFFFFF)
- LLP64 (Windows 64-bit): 8 bytes
- ILP32 on 64-bit kernel (x32 ABI, some embedded): 4 bytes
- Rare / experimental (128-bit address spaces): could be 16 bytes

Minimum guarantee: SIZE_MAX >= 65535 (so at least 16 bits).

*/

size_t counter;


 void create_array(size_t size)
    {
        char my_array[size];
        int i=0;

        while (i<size)
        {
            my_array[i]='A'+i;
            printf("The element %i of the array is \t %c. \n",i,my_array[i]);
            i++;
        }
        
    }

int main(void)
{
    printf("Enter the size of your array:");
    scanf("%zd",&counter);

    create_array(counter);

    return 0; 
}





