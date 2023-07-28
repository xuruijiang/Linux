#include<stdio.h>
#include<unistd.h>
int main()
{

    int ret = fork();
    if(ret > 0)
    {

      printf("you can see me!!!\n");

    }
    else
    {
      printf("oops! you can see me!!!\n");
    }
    
    sleep(1);

 //   int i = 1000;
 //   while(i > 0)
 //   {
 //       printf("hello world! pid: %d \n",getpid());
 //       printf("hello world! pid: %d \n",getppid());
 //       sleep(1);
 //       i--;
 //   }
    
    return 100;
}
