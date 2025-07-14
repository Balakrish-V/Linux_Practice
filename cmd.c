#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int p[2];
    pipe(p);

    if (fork() == 0)
    {
        // Child 1: ps -e
        close(p[0]);              // Close read end
        dup2(p[1], 1);            // Redirect stdout to write end of pipe
        close(p[1]);              // Close the original write end
        execlp("ps", "ps", "-e", NULL);
    }
    else
    {
        if (fork() == 0)
        {
            // Child 2: grep pts/1
            close(p[1]);          // Close write end
            dup2(p[0], 0);        // Redirect stdin to read end of pipe
            close(p[0]);          // Close the original read end
            execlp("grep", "grep", "pts/1", NULL);
        }
        else
        {
            // Parent process
            close(p[0]);
            close(p[1]);
            wait(0);
            wait(0);
        }
    }

    return 0;
}



SUMMARY:

We are simulating this Linux shell command:
ps -e | grep pts/1

This command means:

ps -e: Shows all running processes.
| (pipe): Sends the output of ps -e to the next command instead of printing it on the screen.
grep pts/1: Looks through the input and shows only lines that contain pts/1 (usually a terminal name).


Output:
  1000 pts/1    00:00:00 bash
  1025 pts/1    00:00:00 vim
  1043 pts/1    00:00:00 a.out

This means:

Process 1000 is running bash in terminal pts/1.
Process 1025 is running vim in the same terminal.
Process 1043 is running a.out (our program!) in that terminal.
