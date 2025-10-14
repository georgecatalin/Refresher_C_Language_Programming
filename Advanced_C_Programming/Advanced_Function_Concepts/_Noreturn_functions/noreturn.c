/*
A _Noreturn function is a function that, by design, will not return to its caller. 
This is a function specifier that you can use to give a hint to the compiler, which helps it to perform better
 optimizations and to detect potential programming errors.


How It Works
-------------------

When a compiler sees the _Noreturn specifier on a function declaration, it knows that the code following the function call is 
unreachable. 

This allows the compiler to:

    Optimize Code: The compiler can generate more efficient code by not saving the return address or 
    preserving registers that would be needed if the function were to return.

    Suppress Warnings: It prevents the compiler from issuing warnings about "missing return statements" or "unreachable code" 
    that would otherwise be flagged as potential errors.

    Improve Static Analysis: Tools can use this information to better analyze the program's control flow and find bugs.


*/

#include <stdio.h>
#include <stdlib.h> // For the exit() function
#include <stdnoreturn.h> // Header for noreturn

// Declare a function that will not return
_Noreturn void critical_error(const char *message) {
    fprintf(stderr, "Critical Error: %s\n", message);
    exit(1); // This function terminates the program
}

int main() {
    int data_status = -1;

    if (data_status < 0) {
        critical_error("Invalid data received");
        // The compiler knows this line is unreachable and won't issue a warning.
    }

    // This code would only be executed if the condition above was false.
    printf("Program finished successfully.\n");
    return 0;
}