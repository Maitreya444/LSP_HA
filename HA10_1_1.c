//Write a program which is used to create simple thread by using pthread library.
#include<stdio.h>
#include<pthread.h>
pthread_t tid;

void * threadFunc(void * ptr)
{
    printf("I'm Thread ,Created \n");
    return ((void *)0);
}

int main()
{   
    int create = 0;

    create = pthread_create(&tid, NULL, threadFunc, NULL);

    if(create !=0)
    {
        printf("Error \n");
    }

    printf("Main Thread \n");

    sleep(1); //Sleep function is neccessary here because if sleep function is not called then main thread gets terminated first.

    return 0;
}