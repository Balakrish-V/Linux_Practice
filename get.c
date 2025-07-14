#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int main(int argc, char **argv)
{
    int id;

    // 1. Check for correct usage (exactly 1 argument required)
    if (argc != 2)
    {
        printf("Usage: ./get semnum\n");
        return;
    }

    // 2. Get or create a semaphore set with key=3, 5 semaphores, permissions 0664
    id = semget(3, 5, IPC_CREAT | 0664);
    if (id < 0)
    {
        perror("semget");  // print error if failed
        return;
    }

    printf("id=%d\n", id); // print the semaphore set id

    // 3. Get the value of the semaphore number provided as argument
    int r = semctl(id, atoi(argv[1]), GETVAL);
    if (r < 0)
    {
        perror("semctl"); // print error if failed
        return;
    }

    printf("r=%d\n", r); // print the value of the semaphore
}

SUMMARY:

It connects to a set of semaphores (used for managing access between processes).
It reads and prints the value of one specific semaphore from the set.
You tell it which semaphore to check by giving a number (like 0, 1, etc.) when running the program.
This program is used to check the value of a semaphore.
Think of a semaphore as a counter that helps programs take turns using a shared resource (like a printer, a file, or a sensor). 
It makes sure that two programs don't try to use the same thing at the same time.
This program lets you check the status of a shared resource by reading the value of a semaphore.
It’s useful when you're working on systems where multiple programs run at the same time and need to take turns using something.
It’s a tool for debugging, monitoring, or simply checking if something is free or busy.

Why use this program?
You run the program with one number.(That number tells the program which semaphore you want to check.)
The program tries to connect to a semaphore set.
It reads the value of the semaphore you asked for (based on the number you gave).
It prints out the value.

Real-world analogy:
Imagine a room with a key hanging on a hook.
If the key is there, the bathroom is free.
If the key is missing, someone is using it.

This program is like checking the hook to see if the key (resource) is available or not.

