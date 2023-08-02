#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
    printf("Inside Thread 1 \n");
    int iCnt = 0;

    for(iCnt = 0; iCnt <= 500; iCnt++)
    {
        printf("Thread 1 Number count are %d\n", iCnt);
    }
    pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
    printf("Inside Thread 2 \n");
    int iCnt = 0;

    for(iCnt = 500; iCnt >= 0; iCnt--)
    {
        printf("Thread 2 Number count are %d\n", iCnt);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1;
    pthread_t TID2;

    int ret1 = 0;
    int ret2 = 0;

    ret1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);

    if(ret1 !=0)
    {
        printf("Unable to create Thread1 \n");
        return -1;
    }
    printf("Thread1 is created with ID : %d\n", TID1);

    ret2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);

    if(ret2 !=0)
    {
        printf("Unable to create Thread2 \n");
        return -1;
    }
    printf("Thread2 is created with ID : %d\n", TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    sleep(1);

    printf("End of main thread \n");

    pthread_exit(NULL);

    return 0;
}