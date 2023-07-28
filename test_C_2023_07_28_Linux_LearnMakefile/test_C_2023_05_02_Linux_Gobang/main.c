#include "game.h"

int main()
{
    int quit = 0;
    int select = 0;
    while(!quit)
    {

        Menu();
        scanf("%d",&select);
        switch(select)
        {
            case 1:
                Game();
                break;
            case 0:
                quit = 1;
                printf("ByeBye\n");
                break;
            default:
                printf("Enter Error, Try Again!\n");
                break;
        }//whitch结束
    }//while结束
    return 0;

}//主函数结束
