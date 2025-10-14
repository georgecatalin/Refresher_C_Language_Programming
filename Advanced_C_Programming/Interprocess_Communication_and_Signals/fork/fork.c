#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 20

void child_function()
{
  for (int i = 0; i < MAX_COUNT; i++)
  {
    printf("i am executing this code in the child_function() %s with value %d \n", __func__, i);
  }
  
}

void parent_function()
{
  for (int i = 0; i < MAX_COUNT; i++)
  {
    printf("i am executing this code in the parent_function() %s with value %d \n", __func__, i);
  }
}


int main(void)
{
  pid_t pid;

  pid = fork();

  if(pid == 0)
  {
    puts("I am seeing this from the child process.");
    child_function();
  }
  else if(pid > 0)
  {
    puts("I am seeing this from the parent process.");
    parent_function();
  }
  else
  {
    puts("there was an error when creating the new proces. either the system is ouf of memory or it has exceeded the number of possible processes");
  }



    return 0;
}