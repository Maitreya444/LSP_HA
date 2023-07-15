//Write a program which accpet file name from user and read whole file.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define BLOCKSIZE 1024
int main(int argc , char * argv[])
{
    int Ret = 0;
    int fd =0;
    char Buffer [BLOCKSIZE];

    if(argc !=2)
    {
        printf("Parametres purn taak re\n");
        return -1;
    }

    fd = open (argv[1], Ret);

    if(fd == -1)
    {
        printf("unable to open the file \n");
        return -1;
    }
    while((Ret = read(fd, Buffer, sizeof(Buffer))) !=0)
    {
        write(1, Buffer, Ret);
    }
    close(fd);
    return 0;
}