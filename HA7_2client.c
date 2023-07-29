#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc , char * argv[])
{
    void *ptr = NULL;
    void (*fptr)(int argc, char * argv[]);

    ptr = dlopen("library2.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }

    fptr = dlsym(ptr,"FileCompare");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }
    
    fptr(argc,argv);
    return 0;
}

//LD_LIBRARY_PATH=/Desktop/LSP/HW/Dynamic:$LD_LIBRARY_PATH
//gcc -c -FPIC HA7_1SharedFile.c
//gcc -shared -o library.so HA7_1SharedFile.o
//gcc -rdynamic -o Myexe HA7_1client.c
//./Myexe