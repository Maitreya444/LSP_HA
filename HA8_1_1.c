//Write a program in which parent process waits till its child process terminates
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    int PID = 0;

    PID = getpid();
    
    printf("I'm Child Process and my Parent Process is %d\n", getpid());
}