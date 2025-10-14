#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


void *thread_function(void *arg)
{
    printf("New Thread: Hello! \n");
    sleep(1);
    printf("New Thread: I am done now \n");

    return NULL;
}

int main(void)
{
    pthread_t new_thread = 0;

    printf("Main: a new thread is being created....\n");

    int result = pthread_create(&new_thread, NULL, thread_function, NULL);

    if (result!=0)
    {
        perror("Error during thread create");
        exit(EXIT_FAILURE);
    }
    
    printf("Main: The new thread was created, main thread continues to run \n");
    sleep(2);

    printf("Main: Exiting \n");

    return 0;
}