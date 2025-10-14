#include <stdio.h>

/*
fflush() is a standard C library function used to force the immediate writing of any buffered data to its destination.

In simple terms, it "flushes" the contents of a temporary holding area (a buffer) to ensure that what you've tried to write is actually written.

The Concept of Buffering

To understand fflush(), you first need to know why programs use buffers.

Writing data to a disk, a network, or even the screen is a relatively slow process (an I/O operation). 
For efficiency, your program doesn't write every single character the moment you tell it to. 
Instead, it collects the data in a temporary storage area in memory called a buffer.

The system then writes the data from the buffer to the destination in one larger, more efficient chunk. 
This "flushing" happens automatically when:

    The buffer becomes full.

    You close the file with fclose().

    The program ends normally.

    For screen output (stdout), a newline character (\n) is printed.

fflush() allows you to trigger this write operation manually, at any time.    

Signature:
int fflush(FILE *file_stream)

FILE *stream: This is a pointer to the output stream you want to flush. 
Common examples are stdout (for screen output) or a file pointer you got from fopen().


When to Use fflush()

You need to use fflush() when you can't rely on the automatic flushing behavior.

    Interactive Prompts: This is the most common use case. 
    When you print a prompt to the screen that doesn't end with a newline (\n), 
    the text might get stuck in the buffer and not appear before the program waits for input.

    Data Logging: If you're writing to a log file and your program might crash, 
    you should fflush() after writing a critical message to ensure it's saved to the disk and not lost.

    Inter-Process Communication: When one program is sending data to another, 
    the sending program must flush its output to make the data available for the receiving program to read.

*/

int main(void)
{
    int age;

    //print a text without the line ending character \n
    printf("Enter your age: ");
    
    //flush to stdout
    //fflush(stdout);

    scanf("%d", &age);

    printf("Your age is %d,", age);

    return 0;
}