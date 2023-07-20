#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc , char ** argv[])
{   
    if(argc !=3)                                                        //S 1
    {
        printf("Invalid parametres \n");
        return -1;
    }

    int fd = 0;
    char * DirName = NULL;
    char * FileName =  NULL;
    char * PathFile = NULL;
    struct stat sFileInfo;

    DirName = (char *)malloc(sizeof(char));
    FileName = (char *)malloc(sizeof(char));
    PathFile = (char *)malloc(sizeof(char));

    DirName = strcpy(DirName, argv[1]);
    FileName = strcpy(FileName, argv[2]);

    sprintf(PathFile, "%s/%s", DirName, FileName);          //vvimp step
    if(stat(DirName,&sFileInfo) == -1)
    {
        mkdir(DirName, 0777);
        printf("Dir created \n");
    }
    fd= creat(PathFile, 0777);

    if(fd == -1)
    {
        printf("ERROR \n");
        return -1;
    }
    else
    {
        printf("Success \n");
    }
    close(fd);
    free(DirName);
    free(FileName);
    free(PathFile);
    
    return 0;
}