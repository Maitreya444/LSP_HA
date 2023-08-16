//Write a program which creates such a process which accept signals from the terminal

#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = fork();

    if(iRet == -1)
    {
        printf("ERROR \n");
        return 1;
    }

    if(iRet == 0)
    {
        while(1)
        {
            printf("Hello \n");
            usleep(100);
        }
    }
    else
    {   
        sleep(1);
        kill(iRet,SIGKILL) ; //just a signal
        wait(NULL);
    }
    return 0;
}