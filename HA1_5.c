//Write a program which accpet the file name from user and no of bytes and print all data about file 
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc , char *  argv[])
{
    int fd =0;
    char * Buffer = NULL;
    int size = 0;
    int Ret = 0;

    if(argc !=3)
    {
        printf("less arguments \n");
        return -1;
    }
    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }
    size = atoi(argv[2]);

    Buffer = (char *)malloc(size);

    Ret = read(fd,Buffer,size);
    if(Ret == 0)
    {
        printf("Unable to read data from file \n");
        return -1;
    }
    printf("Data from file is : \n");
    write(1, Buffer, Ret);

    return 0;

}