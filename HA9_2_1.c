#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#define BLOCKSIZE 512

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <first filename> <second filename>\n", argv[0]);
        return -1;
    }

    int pRet1 = 0;
    int pRet2 = 0;
    int fd1 = 0;
    int fd2 = 0;
    int iRet1 = 0;
    int iRet2 = 0;
    int iCnt = 0;
    int iCount = 0;
    char Buffer[BLOCKSIZE];
    char result1[50];
    char result2[50];

    // Create the first process (Process 1)
    pRet1 = fork();

    if(pRet1 == 0) // Child process 1: Count capital letters in demo.txt
    {
        fd1 = open(argv[1], O_RDONLY);
        if(fd1 == -1)
        {
            printf("Error while opening the file %s\n", argv[1]);
            return -1;
        }

        // Count capital letters
        while((iRet1 = read(fd1, Buffer, sizeof(Buffer))) != 0)
        {
            for(iCnt = 0; iCnt < iRet1; iCnt++)
            {
                if(Buffer[iCnt] >= 'A' && Buffer[iCnt] <= 'Z')
                {
                    iCount++;
                }
            }
        }
        close(fd1);

        // Write the count to count.txt
        fd1 = open("count.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
        if(fd1 == -1)
        {
            printf("Error while opening count.txt\n");
            return -1;
        }

        snprintf(result1, sizeof(result1), "Capital letters in %s: %d\n", argv[1], iCount);
        write(fd1, result1, strlen(result1));
        close(fd1);

        exit(0); // Child process 1 exits
    }

    // Create the second process (Process 2)
    pRet2 = fork();

    if(pRet2 == 0) // Child process 2: Count small letters in hello.txt
    {
        fd2 = open(argv[2], O_RDONLY);
        if(fd2 == -1)
        {
            printf("Error while opening the file %s\n", argv[2]);
            return -1;
        }

        iCount = 0; // Reset the count for process 2

        // Count small letters
        while((iRet2 = read(fd2, Buffer, sizeof(Buffer))) != 0)
        {
            for(iCnt = 0; iCnt < iRet2; iCnt++)
            {
                if(Buffer[iCnt] >= 'A' && Buffer[iCnt] <= 'Z')
                {
                    iCount++;
                }
            }
        }
        close(fd2);

        // Write the count to count.txt
        fd2 = open("count.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
        if(fd2 == -1)
        {
            printf("Error while opening count.txt\n");
            return -1;
        }

        snprintf(result2, sizeof(result2), "Capital letters in %s: %d\n", argv[2], iCount);
        write(fd2, result2, strlen(result2));
        close(fd2);

        exit(0); // Child process 2 exits
    }

    // Parent process: wait for both children to finish
    if(pRet1 > 0 && pRet2 > 0)
    {
        wait(NULL); // Wait for child process 1
        wait(NULL); // Wait for child process 2
    }
    else
    {
        printf("Fork failed.\n");
        return -1;
    }

    return 0;
}
