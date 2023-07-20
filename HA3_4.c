//Write a program which accept directory name from user and delete all empty files from that directory.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{   
    DIR * dir;
    struct  dirent * entry;
    
    struct  stat FileInfo;
    int fd =0;

    if(argc !=2)
    {
        printf("Purn parametre taak \n");
        return -1;
    }

    dir = opendir(argv[1]);
    {
        if(argv[1] == NULL)
        {
            printf("ERROR \n");
            return -1;
        }
    }

    if(stat(argv[1], &FileInfo))
    {
        if(FileInfo .st_size == 0)
        {
            unlink
        }
    }
        
}