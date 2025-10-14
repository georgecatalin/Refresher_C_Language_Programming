#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *function_that_returns_values(void *arg)
{
  printf("New Thread: Hello from a thread that returns a value! \n");
  char *message = (char *) malloc(50 * sizeof(char));
  strcpy(message,"->This is the message");
  return (void *) message;
}

int main(int argc, char *argv[])
{
    pthread_t new_thread = 0;
    void *returned_value;

    printf("Main:I am creating a new thread now.\n");

    int result = pthread_create(&new_thread,NULL,function_that_returns_values,NULL);

    if(result!=0)
    {
        perror("Error when creating the new thread.");
        exit(EXIT_FAILURE);
    }

   printf("Main: a new thread was created and i am joining with the new thread.\n");
   pthread_join(new_thread,&returned_value);

   printf("The returned value from the thread is %s \t. \n", (char *) returned_value);

   //cleanup the allocated memory
   free(returned_value);
   returned_value = NULL;

    return 0;
}