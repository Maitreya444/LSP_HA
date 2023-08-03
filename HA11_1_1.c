//Write a program which creates 4 number of threads and our main thread waits till all thread terminates
#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
    printf("This is THREAD 1 \n");
    pthread_exit(NULL);
}

void * ThreadProc2(void * ptr)
{
    printf("This is THREAD 2 \n");
    pthread_exit(NULL);
}

void * ThreadProc3(void * ptr)
{
    printf("This is THREAD 3 \n");
    pthread_exit(NULL);
}

void * ThreadProc4(void * ptr)
{
    printf("This is THREAD 4 \n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1;
    pthread_t TID2;
    pthread_t TID3;
    pthread_t TID4;

    int iRet1 = 0;
    int iRet2 = 0;
    int iRet3 = 0;
    int iRet4 = 0;


    iRet1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);

    if(iRet1 !=0)
    {
        printf("Unable to create a thread \n");
    }

    iRet2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);

    if(iRet2 !=0)
    {
        printf("Unable to create a thread \n");
    }

    iRet3 = pthread_create(&TID3, NULL, ThreadProc3, NULL);

    if(iRet3 !=0)
    {
        printf("Unable to create a thread \n");
    }

    iRet4 = pthread_create(&TID4, NULL, ThreadProc4, NULL);

    if(iRet4 !=0)
    {
        printf("Unable to create a thread \n");
    }

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);
    pthread_join(TID3, NULL);
    pthread_join(TID4, NULL);

    //sleep(1);

    printf("END OF MAIN THREAD \n");

    return 0;
}