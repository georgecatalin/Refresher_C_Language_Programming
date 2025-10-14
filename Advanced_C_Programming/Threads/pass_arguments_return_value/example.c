#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function_with_arguments_and_return(void *arg)
{
  printf("New thread: Hello from the new thread.\n");

  int number =  *(int *) arg;
  
  int *square = (int *) malloc(sizeof(int));
  *square = number * number;

  return (void *) square;
}

int main(int argc, char *argv[])
{
  pthread_t new_thread;


  int number = 46;
  void *retval;

  printf("Main: I create a new thread now.\n");
  int result = pthread_create(&new_thread, NULL, thread_function_with_arguments_and_return, (void *) &number);
 
  if(result!=0)
  {
    perror("Error when creating the new thread.");
    exit(EXIT_FAILURE);
  }

  pthread_join(new_thread,&retval);

  printf("Main: A new thread was created for number %d and the returned value is %d.\n",number, *(int *) retval );

  free(retval);
  retval = NULL;

  return 0;
}