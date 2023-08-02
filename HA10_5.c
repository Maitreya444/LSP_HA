#include<stdio.h>
#include<pthread.h>

void * ThreadProc (void * ptr)
{
    printf("Thread 1 PID from main thread is :%d\n", pthread_self());

    pthread_exit(NULL);
}   

int main()
{
    pthread_t TID;
    int iRet = 0;

    iRet = pthread_create(&TID, NULL,ThreadProc, NULL);

    if(iRet !=0)
    {
        printf("Unable to create a thread \n");
    }

    pthread_exit(NULL);

    printf("End of main \n");

    return 0;
}