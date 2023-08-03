#include"processBar.h"
#include<string.h>
#include<unistd.h>
void processbar()
{
    char bar[NUM];
    memset(bar, '\0', sizeof(bar));
    int cnt = 0;
    char set[] = "\\|/-";
    while(cnt <= 100)
    {
        printf("[%-100s] [%d%%] [%c]\r",bar,cnt,set[cnt%4]);
        fflush(stdout);
        bar[cnt++] = STYLE;
        usleep(90000);

    }
    printf("\n");

}
