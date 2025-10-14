#include <stdio.h>
#include <stdlib.h>

/*
fprintf() is a standard C library function used to write formatted text to a file.

Think of the regular printf() function, which prints formatted text to your console (the screen). 
The f in fprintf() stands for "file"—it does the exact same thing as printf(), but instead of printing to the screen, 
it writes to a file you specify. 

Signature:
int fprintf(FILE * file_stream, const char * format,...)

- FILE *stream: This is a pointer to a FILE object. It's essentially the destination where you want to write your text. 
You typically get this pointer from the fopen() function.
- const char *format: This is the template string that defines how your data should be formatted. It contains regular 
text and special placeholders called format specifiers (e.g., %d, %s).
- ... (ellipsis): These are the variables (e.g., numbers, strings) that will replace the format specifiers in the template string.

The function returns the number of characters successfully written, or a negative number if an error occurs.
*/


char my_string[100];

FILE * file_pointer;

int main() 
{
//write to the file

    if((file_pointer=fopen("test.txt","a")) == NULL)
    {
        puts("Unable to open the file");
        exit(-1);
    }

    fprintf(file_pointer,"Hello from C");

    fclose(file_pointer);

//read the file
   if((file_pointer=fopen("test.txt","r")) == NULL)
   {
      fprintf(stderr,"I could not open the file.");
      exit(-1);
   }

   while (!feof(file_pointer))
   {
      fgets(my_string,100,file_pointer);
      printf("%s",my_string);
   }
    fclose(file_pointer);

    return 0;
}