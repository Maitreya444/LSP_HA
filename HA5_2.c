#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Employee
{
    int id;
    char Sname[20];
    float salary;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employee eobj;
    char Fname[20];
    int fd = 0;

    eobj.id = 111;
    eobj.salary = 89.99777f;
    eobj.Age = 21;
    strcpy(eobj.Sname,"Maitreya");

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&eobj,sizeof(eobj));

    return 0;
}