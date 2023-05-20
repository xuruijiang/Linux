#include <stdio.h>
#include<string.h>
int main()
{

  int i = 0;
  for(; i < 100; i++)
  {
      printf("%d: %s\n",i,strerror(i));
         
  }//for结束
    
  return 0;
}
