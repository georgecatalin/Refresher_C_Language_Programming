/*
sigaction() is the modern and preffered way to handle signals on POSIX-compliant Linux systems
*/

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int signal_number)
{
    printf("I am the function handler() handling the signal number %d.\n",signal_number);
    exit(EXIT_SUCCESS);
}

int main(void)
{
   //we are going to handle/catch in this example a SIGINT signal which is issued when pressing CTRL+C at the keyboard

   //declare and define the sigaction structure which will be used as argument in the sigaction() function call

   struct sigaction sa;

   memset(&sa, 0, sizeof(sa));
  
   /*
   `memset` is a standard C library function used to set a block of memory to a specific value. It is declared in `string.h`. The function takes three arguments: a pointer to the starting address of the memory block, the value to set (converted to an unsigned char), and the number of bytes to set. 

    This function is commonly used to initialize arrays or structures to zero or another value before use, ensuring that there are no leftover or garbage values. For example, `memset(buffer, 0, sizeof(buffer));` will fill the entire buffer with zeros. This is especially important in low-level programming, such as systems or embedded development, where uninitialized memory can lead to unpredictable behavior.
   
   */
    
   sa.sa_handler = handler;
   sa.sa_flags = SA_RESTART; // Restart slow system_calls if blocked by the signals after executing the handler
   sigemptyset(&sa.sa_mask); // // No extra signals to block


   if(sigaction(SIGINT, &sa, NULL) == -1)
   {
    perror("Error when catching the SIGINT error");
    exit(EXIT_FAILURE);
   }



   puts("Press CTRL+C to emit the SIGINT signal to be captured in this process");


   while(1)
   {
    printf("I am running ...");
    fflush(stdout); //need to flush to stdount since no /n is in printf
    sleep(1);
   }



    return 0;
}