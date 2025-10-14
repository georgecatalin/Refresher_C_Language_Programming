#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  char a[] = "19.45 this test";
  char *end;
  float fnumber = strtof(a,&end);

  printf("The conversion from string %s is %f \n", a, fnumber);
  printf("The remaining string is %s", end);
  printf("The first character of the remaining string where conversion stopped is %c. \n", end[0]);
  printf("The first character of the remaining string where conversion stopped is %c. \n", *end);

  char b[] = "3.14 45.66";
  float fnumber1 = strtof(b,&end);
  float fnumber2 = strtof(end,NULL);

  printf("the first number is %f whereas the second number is %f \n", fnumber1, fnumber2);


    return 0;
}