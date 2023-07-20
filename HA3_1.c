//Write a program which accepts two file names from user and copy the contents of an existing file into newly created file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define BLOCKSIZE 1024
int main(int argc , char * argv)
{
    int fd1 =0;
    int fd2 =0;
    int fd3 =0;
    char Buffer [BLOCKSIZE];
    int size = 0;
    
    if(argc !=4)
    {
        printf("Purn argument taak re \n");
        return -1;
    }
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    if((fd1 ==-1) || (fd2 == -1))
    {
        printf("File unable to open \n");
        return -1;
    }
    fd3 = creat(argv[3], 0777);
    if(fd3 == -1)
    {
        printf("Unable to crete file \n");
        return -1;
    }
    else 
    {
        printf("File is created is succssfully\n");
    }
    while(read(fd3 , &Buffer, 1))
    {
        write(fd1, Buffer, 1);
        write(fd2, Buffer, 1);
    }
    printf("Successfull \n");

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}