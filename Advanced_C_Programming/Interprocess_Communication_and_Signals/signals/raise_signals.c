#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
Signals can either by triggered by the OS, or programatically by the developer, inside a process.

int raise(int signal) //fire a signal to the current process
int kill (int signal) //fire a signal to aother process
 
*/

int main(void)
{
    printf("Hello from a program raising a signal.");
    fflush(stdout);
    raise(SIGSTOP); // The same signal can be raised by pressing CTRL+Z at the keyboard ??
    
     printf("I am back in the program .\n");

    return 0;
}

/*
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Interprocess_Communication_and_Signals/signals$ gcc raise_signals.c -o raise_signals
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Interprocess_Communication_and_Signals/signals$ ./raise_signals 
Hello from a program raising a signal.
[1]+  Stopped                 ./raise_signals
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Interprocess_Communication_and_Signals/signals$ ps
    PID TTY          TIME CMD
   2732 pts/0    00:00:00 bash
   5584 pts/0    00:00:00 raise_signals
   5727 pts/0    00:00:00 ps
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Interprocess_Communication_and_Signals/signals$ kill -s SIGCONT 5584
I am back in the program .
[1]+  Done                    ./raise_signals

*/