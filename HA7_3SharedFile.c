#include<stdio.h>
#include "HA7_3SharedFile.h"

void PrimeNo()
{
    int iNo = 0;
    int iCnt = 0;

    printf("Enter a number \n");
    scanf("%d", &iNo);

    for(iCnt =1; iCnt <= iNo; iCnt ++)
    {
        if((iNo % iCnt) ==0)
    
        printf("It is Prime Number \n");
    }
    
}

void PerfectNo()
{
    int iNo = 0;
    int iCnt = 0;
    int iSum = 0;

    printf("Enter a number \n");
    scanf("%d", &iNo);

    for(iCnt =1; iCnt <= iNo/2; iCnt ++)
    {
        if((iNo % iCnt)==0)
        {
            iSum = iSum + iCnt;
        }
    }
    if(iSum == iNo)
    {
        printf("It is Perfect Number \n");
    }
    else
    {
        printf("It is not a Perfect Number \n");
    }
}