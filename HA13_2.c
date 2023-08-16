//Child process and parent process communiacte with each other by signals

#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int iValue = 0;

void handle_sigusr1(int sig)
{
    if(iValue ==0)
    {
    printf("HINT : Remember that multipliation is repetative addition \n");
    }
}

int main()
{
    int Ret1 = 0;
    int Ret2 = 0;

    Ret1 = fork();
    Ret2 = fork();
    
    if(Ret1 == -1)
    {
        printf("Error \n");
        return 1;
    }   

    if(Ret1 == 0)
    {
        sleep(2);
        kill(getppid(), SIGUSR1);
    }

    else    //Parent Process
    {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);


        printf("What is the result of 3 x 5");
        scanf("%d", &iValue);

        if(iValue == 15)
        {
            printf("Right! \n");
        }
        else
        {
            printf("Wrong \n");
        }
        wait(NULL);
    }

    return 0;
}