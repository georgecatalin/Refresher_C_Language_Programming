#include <stdio.h>
#include "libmymath.h"


int main()
{
  int a = 1978;
  int b = 1954;

  int addme = add(a,b);
  int subme = sub(a,b);

  printf("Add = %d \n", addme);
  printf("Sub = %d \n", subme);

  return 0;
}


/*
Let's break down the flags you used:

    -I ../libstatic/: Correctly tells the preprocessor where to find your header files (e.g., libmymath.h).

    -L ../libstatic/: Correctly tells the linker to add ../libstatic/ to the list of directories where it should search for library files.

    -lmymath: This tells the linker, "Look for a file named libmymath.a in the directories specified by the -L flags and link it with my program."


gcc main.c -I ../libstatic/ -L ../libstatic/ -lmymath -o my_program
*/