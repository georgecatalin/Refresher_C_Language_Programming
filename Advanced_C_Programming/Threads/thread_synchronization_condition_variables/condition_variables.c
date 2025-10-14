#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


//initialize the mutex and condition variables
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t my_cond = PTHREAD_COND_INITIALIZER;

//shared variables
int generated_number = 0;
int is_number_generated = 0;

void *thread_consumer_function(void *arg)
{
    printf("Consumer thread: I am starting now with the id->%ld.\n",pthread_self());

    pthread_mutex_lock(&my_mutex);

    while(is_number_generated==0)
    {
        printf("Consumer thread: No data available.I am going to sleep.\n");
        pthread_cond_wait(&my_cond,&my_mutex);
        printf("Consumer thread: I was woke up happily.\n");
    }

    printf("Consumer thread: I got the data\n");
    pthread_mutex_unlock(&my_mutex);


    return NULL;
}

void *thread_publisher_function(void *arg)
{
    printf("Publisher thread: I am starting now with the id->%ld.\n",pthread_self()); 
    sleep(2);

    pthread_mutex_lock(&my_mutex);
    generated_number = 46;
    is_number_generated = 1;  
    printf("Publisher thread: I generated the number %d and I am passing it to the consumer thread.\n", generated_number);
    
    pthread_cond_signal(&my_cond);

    pthread_mutex_unlock(&my_mutex);

    return NULL;
}


int main(int argc, char **argv)
{
    pthread_t consumer_thread, producer_thread;


    puts("Main thread: I am creating the new threads.");
    pthread_create(&consumer_thread,NULL,thread_consumer_function, NULL);
    pthread_create(&producer_thread,NULL,thread_publisher_function,NULL); 

    pthread_join(consumer_thread,NULL);
    pthread_join(producer_thread,NULL);

    puts("Main thread: i am destroying the mutex and condition object");
    pthread_mutex_destroy(&my_mutex);
    pthread_cond_destroy(&my_cond);


    return 0;
}