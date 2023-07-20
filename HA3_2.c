//Write a program to accept directory name and file name from user and check wheather that file in that directory is present or not.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
    if(argc !=2)
    {
        printf("Purn parametre taak \n");
    }
    DIR * dp = NULL;
    struct dirent * entry = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open the directory \n");
        return -1;
    }
    while((entry = readdir(dp)) != NULL)
    {
        if(strcmp(argv[2], entry -> d_name)==0)
        {
            printf("File is present in directory \n");
            break;
        }
    }
    if(entry == NULL)
    {
        printf("It dosent exist");
        return -1;
    }
    closedir(dp);
    return 0;
}