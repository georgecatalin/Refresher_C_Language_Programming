#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    pid_t process_id;
    char buffer[50];

    int file_descriptors[2];
    char *message = "'This is the message to pass'";
    
    //create the pipe

    if(pipe(file_descriptors) == -1)
    {
        perror("Error when creating pipe.");
        exit(EXIT_FAILURE);
    }

    //create the child
    process_id = fork();

    if(process_id>0)
    {
        printf("I am in the parent process with the process id = %d \n",getpid());

        //close the unnecessary pipe ends
        close(file_descriptors[0]);

        //write to the pipe end
        write(file_descriptors[1],message,strlen(message)+1);

        //close the remaining end
        close(file_descriptors[1]);

        //wait for the child process to terminate
        wait(NULL);

    }
    else
    {
         printf("I am in the child process with the process id = %d \n",getpid());

         close(file_descriptors[1]);

         read(file_descriptors[0],buffer,sizeof(buffer));
         printf("I received this message %s.\n", buffer);

         close(file_descriptors[0]);
         
        }

        return 0;

}