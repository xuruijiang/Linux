#include "game.h"

void Menu()
{

    printf("###############################################\n");
    printf("########  1. Play              0. Exit ########\n");
    printf("###############################################\n");
    printf("Please Select# ");
}//Menu结束
//----------------------------手动分割--------------------------------//

void ShowBoard(int board[][COL], int row, int col)
{

}//ShowBoard结束

//----------------------------手动分割--------------------------------//
//4种情况
//NEXT：表明继续
//PLAYER1_WIN: 用户1赢了
//PLARER2_WIN: 用户2赢了
//DRAW：       平局
int IsOver(int board[][COL], int row, int col)
{

    return 0;
}//IsOver函数结束
//----------------------------手动分割--------------------------------//
void PlayerMove(int board[][COL], int row, int col, int who)
{
  

}//PlayerMove函数结束

//----------------------------手动分割--------------------------------//

void Game()
{
    int board[ROW][COL];
    memset(board, '\0', sizeof(board));
    int result = NEXT;

    do
    {
        ShowBoard(board, ROW, COL);
        PlayerMove(board, ROW, COL, PLAYER1);
        result = IsOver(board, ROW, COL);
        if(NEXT != result)
        {
            break;
        }//if结束

        ShowBoard(board, ROW, COL);
        PlayerMove(board, ROW, COL, PLAYER2);
        result = IsOver(board, ROW, COL);
        if(NEXT != result)
        {
            break;
        }//if结束
      

    }while(1);//do while结束 

    ShowBoard(board, ROW, COL);
    switch(result)
    {
        case PLAYER1_WIN:
            printf("player1 win!\n");
            break;
        case PLAYER2_WIN:
            printf("player2 win!\n");
            break;
        case DRAW:
            printf("player1 draw player2!\n");  
            break;
        default:
            //do nothing
            break;
    }//switch结束
}//Game函数结束
