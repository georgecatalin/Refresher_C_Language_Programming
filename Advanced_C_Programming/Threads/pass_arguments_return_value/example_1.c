//this is an example with cast to pointer in the thread function

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *thread_function_with_arguments_and_return(void *arg)
{
  long number = *(long *)arg;

  printf("New Thread: i am in the new thread now with the argument %ld.\n",number);

  pthread_exit((void *) (number * number));
}



int main(int argc, char *argv[])
{
  pthread_t new_thread;
  long number = 46;
  void *retval;
  
  printf("Main: I am starting a new thread now.\n");

  int result = pthread_create(&new_thread,NULL,thread_function_with_arguments_and_return,&number);

  if (result>0)
  {
    perror("Error when creating new thread.");
    exit(EXIT_FAILURE);
  }
  
  pthread_join(new_thread, &retval);

  printf("Main: a new thread was created starting with the number %ld and the returned value %ld\n", number, (long) retval);




    return 0;
}