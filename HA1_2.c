//Write a program which  accpet file name and on mode from user and then open that file in specified mode.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc , char * argv[])
{
    int Mode = 0;
    int fd = 0;

    if(argc !=3)
    {
        printf("Invalid parametres \n");
        return -1;
    }
    if(strcmp(argv[2], "Read"))
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "Write"))
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file");
        return -1;
    }
    else
    {
        printf("File opened successfully with fd %d\n", fd);
    }
    return 0;
}
