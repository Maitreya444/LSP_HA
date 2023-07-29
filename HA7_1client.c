#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)();
    void (*eptr)();
    void (*gptr)();
    void (*hptr)();

    ptr = dlopen("library.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    eptr = dlsym(ptr,"Subtraction");
    if(eptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    gptr = dlsym(ptr,"Multiplication");
    if(gptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    hptr = dlsym(ptr,"Division");
    if(hptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    fptr();
    eptr();
    gptr();
    hptr();
    return 0;
}

//LD_LIBRARY_PATH=/Desktop/LSP/HW/Dynamic:$LD_LIBRARY_PATH
//gcc -c -FPIC HA7_1SharedFile.c
//cc -shared -o library.so HA7_1SharedFile.o
//gcc -rdynamic -o Myexe HA7_1client.c
//./Myexe