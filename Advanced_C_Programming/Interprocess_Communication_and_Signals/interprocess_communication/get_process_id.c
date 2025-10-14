#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
    pid_t mypid = 0, myppid = 0;

    puts("print the process ids");

    mypid = getpid();
    myppid = getppid();

    printf("The process id is %d, whereas the parent process id is %d.\n", mypid, myppid);

    puts("Verify the process ids using shell commands");
    system("ps -ef");




    return 0;
}