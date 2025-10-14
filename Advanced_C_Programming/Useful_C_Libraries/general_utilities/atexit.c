#include <stdio.h>
#include <stdlib.h>

void atsignoff(void);
void aterror(void);


int main(void)
{
    int number = 0;

    atexit(atsignoff);
    
    printf("Enter your number: ");
    scanf("%d",&number);

    if(number<5)
    {
        atexit(aterror);
        exit(EXIT_FAILURE);
    }


    return 0;
}


void atsignoff(void)
{
    puts("I am inside the atsignoff() function");
}

void aterror(void)
{
    puts("I am inside aterror() function");
}

/*
That's an excellent observation and it touches on a key feature of the C language.

You're right, `atexit()` expects a function pointer, but in C, a **function's name**, when used without the calling parentheses `()`, **automatically "decays" into a pointer to that function**. This is a convenience built into the language.

-----

### Function Name vs. Function Pointer

The C compiler is smart enough to understand the context. Since the `atexit()` function's prototype requires a function pointer, the compiler sees `cleanup_first` and automatically converts the function's name into its memory address.

Because of this behavior, the following two lines of code are **completely equivalent**:

```c
// The function name automatically decays into a pointer. This is the common way.
atexit(cleanup_first);

// You can also be explicit by using the address-of operator (&). This is valid but less common.
atexit(&cleanup_first);
```

Most C programmers use the first form because it's cleaner and more idiomatic.

-----

### The Deciding Factor: The Parentheses `()`

The crucial difference is the presence of the parentheses used for a function call.

  * `cleanup_first` ➡️ **A pointer** to the function. You're referring to the function itself.
  * `cleanup_first()` ➡️ **A call** to the function. You're executing the function's code.

So, when you pass `cleanup_first` to `atexit()`, you are correctly passing the address where the function's code resides, which is exactly what a function pointer is.


The `atexit()` function in C registers a specific function to be called automatically when the program terminates normally. This is useful for performing cleanup tasks, such as closing files or freeing memory, ensuring they are executed before the program exits.

-----

### How `atexit()` Works

The `atexit()` function acts like a "to-do" list for program shutdown. You can register one or more functions (at least 32 are guaranteed by the C standard) to be executed upon normal termination.

These registered functions are placed on a stack. When the program terminates by returning from `main()` or by calling the `exit()` function, the system calls these functions in the reverse order of their registration. This is a **Last-In, First-Out (LIFO)** execution order. ↩️

**Important:** These functions are **not** called if the program terminates abnormally, for instance, by a crash (like a segmentation fault) or by calling `_Exit()`, `_exit()`, or `abort()`.

### Syntax

To use `atexit()`, you must include the `<stdlib.h>` header.

The function prototype is:

```c
int atexit(void (*func)(void));
```

  * **`func`**: This is a pointer to the function you want to register. The registered function must take no arguments (`void`) and return no value (`void`).
  * **Return Value**: `atexit()` returns `0` on success and a non-zero value on failure.

### Common Use Cases 🧹

`atexit()` is primarily used for centralized cleanup operations.

  * **Freeing Global Resources**: Deallocating memory that was allocated for the entire program's lifetime.
  * **Closing Files and Connections**: Ensuring all open file streams or network sockets are properly closed.
  * **Deleting Temporary Files**: Removing any temporary files created during execution.
  * **Logging**: Writing a final log message to indicate a clean shutdown.

### Example

Here's a simple program that demonstrates the LIFO execution order of functions registered with `atexit()`.

```c
#include <stdio.h>
#include <stdlib.h>

// First function to be registered
void cleanup_first() {
    printf("Executing cleanup_first(): This was registered first.\n");
}

// Second function to be registered
void cleanup_second() {
    printf("Executing cleanup_second(): This was registered second.\n");
}

int main() {
    printf("main(): Registering cleanup functions.\n");

    // Register the first function.
    if (atexit(cleanup_first) != 0) {
        fprintf(stderr, "Failed to register cleanup_first\n");
        return 1;
    }

    // Register the second function.
    if (atexit(cleanup_second) != 0) {
        fprintf(stderr, "Failed to register cleanup_second\n");
        return 1;
    }

    printf("main(): About to terminate.\n");

    return 0; // Normal termination starts here
}
```

#### Expected Output:

When you compile and run this code, you will see the following output, clearly showing that `cleanup_second` (registered last) is called before `cleanup_first` (registered first).

```
main(): Registering cleanup functions.
main(): About to terminate.
Executing cleanup_second(): This was registered second.
Executing cleanup_first(): This was registered first.
```



*/