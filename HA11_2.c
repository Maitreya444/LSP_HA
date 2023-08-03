#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    printf("This is THREAD  \n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1[10];

    int iRet = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt< 4; iCnt++)
    {   
        if(pthread_create(TID1 + iCnt, NULL, ThreadProc, NULL) !=0)
        {
            printf("ERROR \n");
            return -1;
        }
        printf("Thread %d has started \n", iCnt);
    }

    pthread_join(TID1[iCnt], NULL);
   
    //sleep(1);
    printf("END OF MAIN THREAD \n");

    return 0;
}