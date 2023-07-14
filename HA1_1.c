//Write a program which accepts file name from user and open that file
#include<stdio.h>
#include<fcntl.h>

int main(int argc , char * argv[])
{
    int fd = 0;
    char Fname [20];

    printf("Enter the name of the file you want to open \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file");
        return -1;
    }
    else
    {
        printf("File opend with fd %d\n", fd);
    }
    return 0;
}