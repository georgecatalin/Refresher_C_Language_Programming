#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *)
{
   printf("New thread: Hello from thread_id %ld \n", pthread_self());
 
   pthread_exit(NULL);
   return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t new_thread;

  printf("Main: I am creating a new thread now. \n");
  int result = pthread_create(&new_thread,NULL,thread_function,NULL);

  pthread_join(new_thread,NULL);
  printf("Main: I waited till the complete execution of the thread.\n");

   return 0;
}