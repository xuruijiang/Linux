#include "ProcBar.h"

void process_bar()
{
    const char *lable = "|/-\\";
    char bar[NUM];
    memset(bar, '\0', NUM);
    int i = 0;
    while(i < NUM - 1 )
    {
        
        bar[i] = '#';
        printf("[%-100s] [%-3d%%] [%c]\r",bar,i + 1,lable[i%4]);
        usleep(50000);
        i++;
    }
    printf("\n"); 
}//函数结束
