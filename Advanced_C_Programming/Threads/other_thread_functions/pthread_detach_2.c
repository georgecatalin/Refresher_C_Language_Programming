#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function_detached(void *arg)
{
   puts("New thread: Hello from new thread");
   pthread_detach(pthread_self());

   puts("New thread: Good Bye from new thread");

   return NULL;
}


int main(int argc,char *argv[])
{
   pthread_t new_thread;

   puts("Main: I am creating a new thread.");

   int result = pthread_create(&new_thread, NULL, thread_function_detached,NULL);

   if (result !=0)
   {
     perror("Error when creating thread:");
     exit(EXIT_FAILURE);
   }
   
   sleep(2);

    puts("Main: I am exiting main().");
    return 0;
}