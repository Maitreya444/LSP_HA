//Write a program which accept directory name from user and print all the file names and types of that directory.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc , char * argv[])
{
    DIR * dp = NULL;
    struct dirent * Files = NULL;

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Kahich nahi dhakvaila \n");
        return -1;
    }
    printf("File are : \n");
    while((Files = readdir(dp)) !=NULL)
    {
        printf("%s\n", Files -> d_name);
    }
    return 0;
}