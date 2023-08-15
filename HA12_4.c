//Write a program which map any file in memory and read the data from that mapped file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int fd = open("./ABC.txt", O_RDONLY, S_IRUSR | S_IWUSR);
    struct stat sb;
    char* memoryfile = 0;

    if(fstat(fd,&sb) ==-1)
    {
        printf("Cant get file size \n");
        return -1;
    }
    printf("File size is %d\n", sb.st_size);

    memoryfile = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE,                     fd,0);
                                         //Read     //Visible only to process        start from begining

    printf("Displaying words from file \n");

    for(int iCnt = 1; iCnt<= 1; iCnt++)
    {
        printf("%s\n", memoryfile);
    }
    printf("\n");

    munmap(memoryfile, sb.st_size);
    close(fd);
    return 0;
}