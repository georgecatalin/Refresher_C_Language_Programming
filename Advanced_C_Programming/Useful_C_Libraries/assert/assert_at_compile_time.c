#include <stdio.h>
#include <assert.h>

#define x 20

int main(void)
{
   
   static_assert(x < 10,"x is greater than 10"); //The first parameter of static_assert() must be a constant


    return 0;
}

/*

georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Useful_C_Libraries/assert$ gcc assert_at_compile_time.c -o assert_c
In file included from assert_at_compile_time.c:2:
assert_at_compile_time.c: In function ‘main’:
assert_at_compile_time.c:9:4: error: static assertion failed: "x is greater than 10"
    9 |    static_assert(x < 10,"x is greater than 10"); //The first parameter of static_assert() must be a constant
      |    ^~~~~~~~~~~~~



*/