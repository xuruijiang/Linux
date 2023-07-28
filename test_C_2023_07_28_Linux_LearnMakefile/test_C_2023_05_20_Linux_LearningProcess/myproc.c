#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id =fork();
    if(id == 0)
    {
        //child
        int cnt = 5;
        while(cnt)
        {
            printf("child[%d] is running: cnt is %d\n",getpid(),cnt);
            cnt--;
            sleep(1);

        }//while
        exit(0);
        
    }//if结束
    
   
    sleep(10);
    printf("Father wait begin!\n");
    
    //pid_t ret = wait(NULL);
    //pid_t ret = waitpid(id,NULL,0);  等待指定一个进程
    pid_t ret = waitpid(-1,NULL,0); //等待任意一个子进程
    if(ret > 0)
    {

        printf("Father wait: %d success!\n",ret);
    }//if
    else
    {
        printf("Father wait failed!\n");
    }//else
    
    sleep(5);

    return 0;
}


/*
int main()
{
    
    //exit(12);
    int i = 0;
    for(; i < 5; i++)
    {
          printf("%d: %s\n",i,strerror(i));
         
    }//for结束
    
    sleep(5);
    return 0;
}
*/
