#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void * thread_function_with_exit(void *arg)
{
   long thread_id = (long) arg;
   printf("New thread: a new thread was created with id %ld.\n", thread_id);
   pthread_exit((void *) (thread_id *10));

    //this will never be executed
    printf("New thread: this part will never be executed.\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t new_thread;
    long id = 46;

    void *retval;

    printf("Main: a new thread is being created . \n");
    int result = pthread_create(&new_thread,NULL,thread_function_with_exit, (void *) id);

    if (result!=0)
    {
        perror("Error when creating thread:");
        exit(EXIT_FAILURE);
    }
    
    pthread_join(new_thread,&retval);

    printf("Main: a new thread was created and it returned this value -> %ld \n", (long) retval);


    return 0;
}