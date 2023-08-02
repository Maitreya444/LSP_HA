//Write a program which creates single thread and it accepts one value from user and it return some value to user thread
#include<stdio.h>
#include<pthread.h>

void * ThreadProc (void* ptr)
{
    printf("Value from main thread ie from user is %d\n", (int)ptr);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int iRet = 0;
    int iNo = 0;

    printf("Enter a Value \n");
    scanf("%d", &iNo);

    iRet = pthread_create(&TID, NULL, ThreadProc, (int*)iNo);

    if(iRet !=0)
    {
        printf("Unable to create a Thread \n");
    }
    pthread_join(TID,NULL);

    printf("END OF MAIN \n");

    pthread_exit(NULL);

    return 0;
}