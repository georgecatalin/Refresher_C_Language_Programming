#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_attr_t attr;

void *thread_function_stack_management(void *arg)
{
   puts("New thread: Hello a new thread is created.");
   size_t this_threads_stacksize = 0;

   pthread_attr_getstacksize(&attr, &this_threads_stacksize);

   printf("The stacksize is %ld for this thread id ->%ld", this_threads_stacksize, pthread_self());

   return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t this_thread;
  size_t global_stacksize = 0;

  //initialize the attribute obkect
  pthread_attr_init(&attr);

  //get the value of the default stacksize
  pthread_attr_getstacksize(&attr, &global_stacksize);

  printf("The default value of the stacksize for this system is %ld bytes.\n", global_stacksize);

  //set the value of the stacksize to a new value
  pthread_attr_setstacksize(&attr, 9000000);

  printf("The NEW default value of the stacksize for this system is %ld bytes.\n", global_stacksize);

  //create a new thread and check its stacksize
  int result = pthread_create(&this_thread,&attr,thread_function_stack_management, NULL);

  if (result!=0)
  {
    perror("Error when creating the new thread");
    exit(EXIT_FAILURE);
  }
  
  pthread_join(this_thread,NULL);
  puts("Main: a new thread has been created.");


    return 0;
}