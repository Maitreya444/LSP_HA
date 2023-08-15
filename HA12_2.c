//Write a program which creates 2 processess and that two processess can communicate with each other by using concept of shared memory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;
    char * ptr = NULL;
    int iRet = 0;

    printf("SHM is running\n");

    shmid = shmget(Key,shmsize,IPC_CREAT | 0666);

    printf("Shared memory allocated successfully \n");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory attached successfully \n");
    }

    iRet = fork();

    if(iRet == 0)
    {
        printf("Shared memory recieved %d\n", ptr);
        shmdt(ptr);
    }
    else
    {   
        printf("This is parent \n");
        shmdt(ptr);
    }

    return 0;
}