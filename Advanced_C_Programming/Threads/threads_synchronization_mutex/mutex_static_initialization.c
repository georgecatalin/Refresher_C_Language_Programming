#include <stdio.h>
#include <pthread.h>
#define  NUMBER_THREADS 10

int counter = 0;//global variable which will be shared amongst threads


void *thread_function(void *arg)
{
   printf("Inside thread \t -> %ld\n", pthread_self());
   
   counter ++;
   printf("%ld\t\t:\t\t%d\n",pthread_self(),counter);

    return NULL;
}


int main(int argc, char **argv)
{
    pthread_t threads[NUMBER_THREADS];

    //Static initializer of mutex object
    pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

    for (size_t i = 0; i < NUMBER_THREADS; i++)
    {
        pthread_create(&threads[i],NULL,thread_function,NULL);
    }
    
    for (size_t i = 0; i < NUMBER_THREADS; i++)
    {
        pthread_join(threads[i],NULL);
    }
    
    printf("The value of counter is %d\n", counter);


    return 0;
}