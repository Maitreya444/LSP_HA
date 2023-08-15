//Write a program which creates one child process, child process write something in unnamed pipe and parent process
//read the data from the pipe

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd[2];
    int iRet = 0;
    int A = 0;
    int B = 0;

    if(pipe(fd) == -1)
    {
        printf("Error opening pipe \n");
        return 1;
    }
    iRet = fork();

    if(iRet == 0)
    {
        printf("Child process scheduled for writing into pipe \n");
        close(fd[0]);
        printf("Enter a Number \n");
        scanf ("%d", &A);
        write(fd[1], &A, sizeof(int));
        close(fd[1]);
    }
    else
    {
        printf("Parent process is scheduled for writing into pipe \n");
        read(fd[0],&B ,sizeof(int));
        close(fd[0]);
        printf("Data from pipe is via child process : %d\n", B);
    }
    return 0;
}