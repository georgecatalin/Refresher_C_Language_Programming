#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//declare pthread_once_t special control variable
pthread_once_t control_variable = PTHREAD_ONCE_INIT;

void init_function(void)
{
    //in a normal application it is here where you open database connections or open files or setup shared resources
    printf("Initializing module now....\n");
}

void *thread_function(void *arg)
{
    long thread_id = (long) arg;
    printf("Attempting to initialize the module in thread id -> %ld\n",thread_id);

    pthread_once(&control_variable,init_function);

    printf("The mdule is ready for use.\n");
 

    return NULL;
}


int main(void)
{
    pthread_t threads[10];

    //create threads
    for (size_t i = 0; i < 10; i++)
    {
        pthread_create(&threads[i],NULL,thread_function,(void *) i);
    }
    

    //join the threads
    for (size_t i = 0; i < 10; i++)
    {
       pthread_join(threads[i],NULL);
    }
    
    puts("Main:All threads are finished");


    return 0;
}