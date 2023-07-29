#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;

    Ret = fork();

    if(Ret == 0)
    {
        execl("./ChildProcess", "NULL", NULL);
    }
    else if (Ret > 0)
    {
        printf("Parent Process is running with PID %d\n", getppid());
        sleep(1);
        {}
    }

    return 0;
}