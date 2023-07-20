//Write a program which writes structure in file. Structure shold contain information of student.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int age;
};

int main(int argc, char * argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd =0;

    printf("Enter the file name \n");
    scanf("%s", Fname);

    fd= open(Fname, O_RDONLY);

    read(fd, &sobj, sizeof(sobj));

    printf("Roll Number : %d : \n", sobj.Rollno);
    printf("Name : %s :\n",sobj.Sname);
    printf("Marks : %f : \n", sobj.Marks);
    printf("Age : %d : \n", sobj.age);

    close(fd);

    return 0;
}
