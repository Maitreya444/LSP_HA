// Write a program which creates 3 diferrent processes internally as process 2, process 3 and process 4
//                                                                     my son     my grandson   my great grandson
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int parent = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;

    parent = fork();

    if (parent == 0)
    {
        printf("My child is running and its parent is %d %d\n", getpid(), getppid());
    }

    p2 = fork();

    if (p2 == 0)
    {
        printf("My grandson is running its parent is %d %d\n", getpid(), getppid());
    }

    p3 = fork();
    {
        printf("My great grandson is running its parent is %d %d\n", getpid(), getppid());
    }

    return 0;
}