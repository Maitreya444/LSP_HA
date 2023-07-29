//Write a program which create three levels of process hiearchy where process 1 creates process 2 and it internally creates process 2
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int GP = 0;
    int PP = 0;
    int CP = 0;

    GP = fork();
    
    if(GP == 0)
    {
        printf("HI I'm Child of my Parent GP and my id is PP %d %d\n ",getppid(), getpid());
    }

    PP = fork();
    
    if(PP == 0)
    {
        printf("HI I'm Child of my Parent PP and my id is CP %d %d\n ",getppid(), getpid());
    }
    return 0;
}