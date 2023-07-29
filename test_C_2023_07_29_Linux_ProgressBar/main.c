#include "processBar.h"

int main()
{
   int i = 10; 
   for(; i >= 0; i--)
   {
        printf("%-2d\r",i);
        fflush(stdout);
        sleep(1);

   }
    printf("\n"); 
    return 0;
}
