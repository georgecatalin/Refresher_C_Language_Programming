#include <stdio.h>
#include "myLib.h"


int main(void)
{
   function1(); //function from the dynamic library


    return 0;
}


/*
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ gcc -c main.c -I ../libshared/ -o main.o
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ ls -lh
total 8,0K
-rw-rw-r-- 1 georgeca georgeca  127 Sep 29 16:37 main.c
-rw-rw-r-- 1 georgeca georgeca 1,4K Sep 29 16:39 main.o
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ gcc main.o -L ../libshared/ -lmylib -o my_program_dynamic
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ ls
main.c  main.o  my_program_dynamic
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ ./my_program_dynamic 
./my_program_dynamic: error while loading shared libraries: libmylib.so: cannot open shared object file: No such file or directory
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ export LD_LIBRARY_PATH=../libshared/
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Static_Libraries_and_Shared_Objects/Shared_Objects/myprogram$ ./my_program_dynamic 
Hello from dynamic library function1()georgeca@georgeca-VirtualBox:~/my_sandbox/


*/