//Write a program which accept file name which contains data. We have to accept file names whose size is greater than 10 bytes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    char filename[100];
    struct stat file_stat;

    if(argc !=2)
    {
        printf("Purn values taak \n");
        return -1;
    }

    if(stat(argv[1], &file_stat)==0)
    {
        if(file_stat.st_size > 10)
        {
            printf("Greater than 10 byets \n");
        }
        else
        {
            printf("Not greater than 10 bytes \n");
        }
    }
    return 0;
}