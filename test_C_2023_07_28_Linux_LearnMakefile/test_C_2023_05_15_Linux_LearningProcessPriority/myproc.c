#include<stdio.h>
#include<unistd.h>
int main()
{
    while(1)
    {
        printf("I am a process. pid: %d, ppid: %d \n",getpid(),getppid());
        sleep(1);
    }
    return 0;
}
