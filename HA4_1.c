//Write a program which is used to demonstate the concept of IO redirection
#include<stdio.h>
#include<fcntl.h>

int main(int argc , char * argv[])
{   
    int fd = 0;
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;
    
    scanf("%d", &iNo1);
    scanf("%d", &iNo2);
    iAns = iNo1 + iNo2;
    printf("Addition is %d\n", iAns);
    return 0;
}
//./Myexe > Addition.txt < Input.txt