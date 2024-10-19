/*Write a program which creates new process which is responsible to write all file names which are present on desktop in demo file
which should be created newly*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#define DESKTOP_PATH  "/home/maitreya/Desktop"
#define BLOCKSIZE 512

int main(int argc, char * argv[])
{
    if(argc!=2)
    {   
        printf("Please give 2 parametres \n");
        return -1;
    }

    struct dirent * Files = NULL;
    DIR * dp = NULL;
    int fd = 0;
    int pRet = 0;
    int fRet = 0;
    char Buffer [BLOCKSIZE];

    pRet = fork();

    if(pRet == 0)
    {
        fd = open(argv[1],O_RDWR);

        if(fd != -1)
        {
            printf("File is existing\n");
        }
        else
        {
            fd = creat(argv[1],0777);
            if(fd != -1)
            {
                printf("New file gets created\n");
            }
        }
        DIR * dp = opendir(DESKTOP_PATH);

        if(dp == NULL)
        {
            printf("Cant open the directoty \n");
            return -1;
        }

        while((Files = readdir(dp)) != NULL)
        {
            if(Files -> d_type == DT_REG)
            {
                snprintf(Buffer, sizeof(Buffer), "%s\n", Files -> d_name);
                write(fd, Buffer, strlen(Buffer));
            }
        }
        closedir(dp);
        close(fd);

        printf("File names have been written to %s\n", argv[1]);
        exit(0);
    }
    else if(pRet > 0) // Parent process
    {
        wait(NULL); // Wait for child process to finish
    }
    else
    {
        printf("Fork failed.\n");
        return -1;
    }

    return 0;
}
