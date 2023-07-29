#include<stdio.h>
#include<stdbool.h>
#include<fcntl.h>
#include<unistd.h>
#include "HA7_2SharedFile.h"
int FileCompare(int argc , char * argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int con1 = 0;
    int con2 = 0;
    int iCnt = 0;

    fd1 = open(argv[1], O_RDONLY);
    if(argv[1] == NULL)
    {
        printf("Unable to open file \n");
        return -1;
    }

    fd2 = open(argv[2], O_RDONLY);
    if(argv[2] == NULL)
    {
        printf("Unable to open file \n");
        return -1;
    }
    while((read(fd1, &con1, 1) >0)&&(read(fd2,&con2,1)>0))
    {
        if(con1 != con2)
        {
            printf("File not same \n");
            return -1;
        }
    }
    if((con1 == con2))
    {
        printf("File is same \n");  
    }
    else
    {
        printf("Files are not same \n");
    }
    return 0;
}
/*The function enters a loop that reads one character at a time from both files using the read function. 
Inside the loop, it compares the characters (con1 and con2). If the characters are different, 
the function prints a message indicating that the files are different,it returns with an error code*/

//abc.txt                        //xyz.txt
//ABCDE   (con1)                  ABCDE   (con2)
//fd1 (argv[1])                 fd2(argv[2])