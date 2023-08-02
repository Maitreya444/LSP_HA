//Write a program which creates a single thread and we havr to pass parametre to that thread from main thread
#include<stdio.h>
#include<pthread.h>

void * ThreadProc (void* ptr)
{
    printf("Inside Thread1 and value recieved by main thread is %d\n", (int)ptr);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int iNo = 69;
    int iRet = 0;

    iRet = pthread_create(&TID, NULL, ThreadProc, (int*)iNo);

    if(iRet !=0)
    {
        printf("Unable to create the Thread \n");
    }

    printf("End of main thread \n");

    pthread_exit(NULL);

    return 0;
}