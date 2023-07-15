//Write a program which accept file name from user and write string in that file.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
    int fd =0;
    char buffer [] = "Demo.txt";
    char word [50] = "My Sakshi BossLady <3";

    if(argc !=2)
    {
        printf("Ayy Purn parametre taak re.\n");
        return -1;
    }

    fd = open(buffer, O_WRONLY);
 
    if(fd == -1)
    {   
        printf("Unable to create it \n");
        return -1;
    }

    write(fd, word, strlen(word));

    printf("Dont worry file got updated! \n");

    close(fd);

    return 0;
}