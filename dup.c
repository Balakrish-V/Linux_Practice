
#include <stdio.h>    // For printf()
#include <unistd.h>   // For dup(), write()
int main()
{
    int newfd;
    newfd = dup(1);  // Duplicate stdout (file descriptor 1)

    printf("new fd = %d\n", newfd);
    write(newfd, "abcdef\n", 7);

    return 0;
}

SUMMARY:

dup(1) makes a copy of the stdout file descriptor.
The new file descriptor points to the same output (our terminal).
We can use it with write() to print messages without using printf().

* Imagine stdout is a pipe to your terminal. dup() gives you a second pipe connected to the same terminal, so you can write through either one.

USECASE:
You have a pipe (stdout) that goes to your terminal.
Normally, everything you print goes through this one pipe (fd = 1).
But sometimes, you want to temporarily change where your output goes (for example, send it to a file instead).
If you change the original pipe (stdout), you lose the connection to your terminal.
So before you change it, you make a copy of the original pipe with dup().
This way, you keep a backup “second pipe” that still points to the terminal.
