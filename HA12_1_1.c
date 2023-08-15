//Write a program which is used to create unnamed pipe. Parent process creates new child process and both the processess will 
//communicate with each other

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd[2];
    int iRet = 0;
    char iNo [] = "Maitreya";
    char Buffer[100];

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
        write(fd[1], iNo, strlen(iNo));
        exit(0);
    }
    else
    {
        printf("Parent process is scheduled for writing into pipe \n");
        read(fd[0],Buffer ,sizeof(Buffer));
        printf("Data from pipe is : %s\n",Buffer );
    }
    return 0;
}