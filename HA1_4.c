//Write a program which accept file name from user and print all info about that file.
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>

int main(int argc , char * argv[])
{
    struct stat sobj;
    int fd =0;
    if(argc !=2)
    {
        printf("Insufficient argument \n");
        return -1;
    }
    fd = open (argv[1], O_RDONLY);
    fstat(fd, &sobj);

    printf("File name : %s\n", argv[1]);
    printf("File Size is : %d\n", sobj.st_size);
    printf("File Inode : %d\n", sobj.st_ino);
    return 0;

}