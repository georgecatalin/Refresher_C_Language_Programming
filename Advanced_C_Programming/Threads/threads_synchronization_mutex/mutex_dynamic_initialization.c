#include <stdio.h>
#include <pthread.h>

pthread_mutex_t my_mutex;

int j = 0; //global variable which is shared amongst the threads

void *thread_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);

    printf("\n\n");

    int i;
    for(i = 0; i<10; i++)
    {
        printf("%ld: %d ", pthread_self(), j);
        j++;
    }
  
    pthread_mutex_unlock(&my_mutex);


    return NULL;
}


int main(int argc, char **argv)
{
   pthread_t thread1, thread2;

   pthread_mutex_init(&my_mutex,NULL);

   pthread_create(&thread1, NULL, thread_function, NULL);
   pthread_create(&thread2,NULL,thread_function,NULL);

   pthread_join(thread1,NULL);
   pthread_join(thread2,NULL);

   pthread_mutex_destroy(&my_mutex);


    return 0;
}