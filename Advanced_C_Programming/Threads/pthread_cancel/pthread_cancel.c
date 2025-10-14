#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg)
{
   printf("New thread: Hello from thread %ld.\n", pthread_self());

   pthread_cancel(pthread_self());
   puts("New thread: I received a request to terminate.");

   return NULL;
}

int main(void)
{
  pthread_t this_thread;

  int result = pthread_create(&this_thread,NULL,thread_function,NULL);
  
  pthread_join(this_thread, NULL);

  puts("Main: main() function is finishing");


    return 0;
}