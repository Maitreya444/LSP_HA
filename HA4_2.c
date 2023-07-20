//Write a program which accept directory name from user and create new directory of that name.
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    if(argc !=2)
    {
        printf("Purn parametre taak re \n");
        return -1;
    }

    fd = mkdir(argv[1], 0777);

    if(argv[1] == NULL)
    {
        printf("Error while creating file \n");
        return -1;
    }
    else
    {
        printf("File created successgully \n");
    }
    return 0;
}