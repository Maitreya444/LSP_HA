//Write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    struct dirent * Files = NULL;
    DIR * dp = NULL;
    int iCnt = 0;
    char Buffer[10];
    int sourcefd = 0;
    int destfd = 0;
    int bytesread = 0;
    struct stat filestat;
    char filepath[512];

    //Check arguments
    if(argc !=3)
    {
        printf("Invalid arguments \n");
        return -1;
    }

    //Open directory
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Error while opening directory \n");
        return -1;
    }

    //open / create a file
    destfd = open(argv[2], O_RDONLY | O_CREAT | O_RDWR, 0666);
    
    if(destfd == -1)
    {
        printf("Error creating output file \n");
        closedir(dp);
        return -1;
    }

    //read filenames and skip . and .. of the directory one by one
    while((Files = readdir(dp)) != NULL)
    {
        if(strcmp(Files -> d_name, ".") == 0 || strcmp(Files -> d_name, "..") == 0)
        {
            continue;
        }

        //filepath contains full file path. 1st %s is replaced by directory path, 2nd /%s is replaced by file names
        snprintf(filepath, sizeof(filepath), "%s/%s", argv[1], Files -> d_name);
    
        //stat of that file at current loop
        if(stat(filepath, &filestat) == -1)
        {
            printf("Error getting stats for file %s\n", filepath);
            return -1;
        }   

        //If file is regular file then open it and read it
        if(S_ISREG(filestat.st_mode))
        {
            sourcefd = open(filepath, O_RDONLY);

            if(sourcefd == -1)
            {
                printf("Error opening file %s\n", filepath);
                return -1;
            }
        }

        //read 10 bytes 
        bytesread = read(sourcefd, Buffer, sizeof(Buffer));
        if(bytesread == -1)
        {
            printf("Error reading file %s\n", filepath);
            close(sourcefd);
            return -1;
        }

        //write it into output file
        if(write(destfd, Buffer, bytesread) == -1)
        {
            printf("Error writing output file %s\n", argv[2]);
        }
    }

    close(sourcefd);

    closedir(dp);
    close(destfd);

    printf("First 10 bytes from all regular files have been copied to %s\n", argv[2]);

    return 0;
}
