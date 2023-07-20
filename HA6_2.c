#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{   
    if(argc !=2)
    {
        printf("Invalid paramtres \n");
        return -1;
    }
    char FileName[BLOCKSIZE] = 'hole.txt';
    int fd = 0;

    fd = open(FileName, O_RDWR);

    if(fd == -1)
    {
        printf("ERROR \n");
        return -1;
    }
    
}