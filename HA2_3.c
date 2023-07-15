//Write a program which accept directory name from user and print all file names from that directory. (LS command)
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
int main(int argc , char * argv[])
{
    /*  LS command internally karat asel :
    1. user kadun dir name (open dir karaicha)
    2. display karel files sarv 
    3. displayt karaila te stat use karat asel.(wrong thought)
    4. opendir vapraicha, struct dirent point kartoy Files ani sadhtya 
    */
    DIR * dp = NULL;
    struct dirent * Files = NULL;   //5. struct dirent point kartoy Files ani sadhya NULL ahae.
    if(argc !=2)
    {
        printf("Argument kami takle purn taak \n");
        return -1;
    }

    dp = opendir(argv[1]);  
    if(dp == NULL)
    {
        printf("Directory open nai hou shakat \n");
        return -1;
    }
    printf("Files in directory are \n");

    while((Files = readdir(dp)) != NULL)    //6. readdir use karun sarv files read karaiche NULL hot nai toparanta.
    {
        printf("%s\n",Files -> d_name);     //7. d_name he dirent header file amdhe ahae predefined, apan d_name ch use karaicha ani he file name represnt karta.
    }
    closedir(dp);
    return 0;
}