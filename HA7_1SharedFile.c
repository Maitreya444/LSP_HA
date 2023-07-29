#include<stdio.h>
#include "HA7_1SharedFile.h"

void Addition()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;

    printf("Enter number 1 \n");
    scanf("%d", &iNo1);

    printf("Enter number 2 \n");
    scanf("%d", &iNo2);

    iAns = iNo1 + iNo2;

    printf("Addition is : %d\n", iAns);
}

void Subtraction()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;

    printf("Enter number 1 \n");
    scanf("%d", &iNo1);

    printf("Enter number 2 \n");
    scanf("%d", &iNo2);

    iAns = iNo1 - iNo2;

    printf("Subtraction is : %d\n", iAns);
}

void Multiplication()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;

    printf("Enter number 1 \n");
    scanf("%d", &iNo1);

    printf("Enter number 2 \n");
    scanf("%d", &iNo2);

    iAns = iNo1 * iNo2;

    printf("Multiplication is : %d\n", iAns);
}

void Division()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;

    printf("Enter number 1 \n");
    scanf("%d", &iNo1);

    printf("Enter number 2 \n");
    scanf("%d", &iNo2);

    if(iNo2 ==0)
    {   
        printf("Enter +ve Value");
        return;
    }

    iAns = iNo1 / iNo2;

    printf("Division is : %d\n", iAns);
}