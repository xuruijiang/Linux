#include "game.h"

int x = 0;
int y = 0;
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
    printf("\e[1;1H\e[2J"); 
    //数组进行可视化
    printf("  ");
    int i = 1;
    for(; i <= col; i++)
    {
        printf("%3d",i);
    }//for

    printf("\n");
    for(i = 0; i < row; i++)
    {
      int j = 0;
      printf("%2d ",i+1);
      for(; j < col; j++)
      {
          if(board[i][j] == 0)
          {
              printf(" . ");
          }//if
          else if(board[i][j] == PLAYER1)
          {
              printf(" 𐩒 ");
          }//else if
          else
          {
              printf(" ⏺ ");
          }//else

      }//内for
      printf("\n");
    }//外for
}//ShowBoard结束

//----------------------------手动分割--------------------------------//
int ChessCount(int board[][COL], int row, int col, enum Dir d)
{
    int _x = x - 1;
    int _y = y - 1;

    int count = 0;
    while(1)
    {
      switch(d){
          case LEFT:
              _y--;
              break;
          case RIGHT:
              _y++;
              break;
          case UP:
              _x--;
              break;
          case DOWN:
              _x++;
              break;
          case LEFT_UP:
              _x--;
              _y--;
              break;
          case LEFT_DOWN:
              _x++;
              _y--;
              break;
          case RIGHT_UP:
              _x--;
              _y++;
              break;
          case RIGHT_DOWN:
              _x++;
              _y++;
              break;
          default:
              //Do Nothing
              break;

      }//switch

      if(_x < 0 || _x > row - 1 || _y < 0 || _y > col - 1)
      {
        break;
      }//if结束
      //合法
      if(board[x -1][y - 1] == board[_x][_y])
      {
        count++;
      }//if结束
      else
      {
        break;
      }//else结束
    }//while
    return count;
}//函数ChessCount结束

//----------------------------手动分割--------------------------------//
//4种情况
//NEXT：表明继续
//PLAYER1_WIN: 用户1赢了
//PLARER2_WIN: 用户2赢了
//DRAW：       平局
int IsOver(int board[][COL], int row, int col)
{
    int count1 = ChessCount(board, row, col, LEFT) + ChessCount(board,row, col, RIGHT) + 1;
    int count2 = ChessCount(board, row, col, UP) + ChessCount(board,row, col, DOWN) + 1;
    int count3 = ChessCount(board, row, col, LEFT_UP) + ChessCount(board,row, col, RIGHT_DOWN)  + 1;
    int count4 = ChessCount(board, row, col, LEFT_DOWN) + ChessCount(board,row, col, RIGHT_UP) + 1;
    if(count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5)
    {
        if(board[x-1][y-1] == PLAYER1)
        {
          return PLAYER1_WIN;
        }//if结束
        else
        {
          return PLAYER2_WIN;
        }//else结束
    } //if结束 
    
    int i = 0;
    for(; i < row; i++)
    {
        int j = 0;
        for(; j < col; j++)
        {
            if(board[i][j] == 0)
            {
                return NEXT;

            }//if结束
        }//for结束

    }//for结束

    return DRAW;
}//IsOver函数结束
//----------------------------手动分割--------------------------------//
void PlayerMove(int board[][COL], int row, int col, int who)
{
    
    while(1)
    {  
        printf("Player[%d] Please Enter Your Pos# ",who);
        scanf("%d%d",&x,&y);
        if(x < 1 || x > row || y < 1 || y > col)
        {
            printf("Pos Is Not Right!\n");
            continue;
        }//if结束 
        if(board[x-1][y-1] != 0)
        {
            printf("Pos Is Occupied!\n");
            continue;

        }//if结束

        board[x-1][y-1] = who;
        break;

    }//while结束
}//PlayerMove函数结束

//----------------------------手动分割--------------------------------//

void Game()
{
    int board[ROW][COL];
    memset(board, 0, sizeof(board));
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

    ShowBoard(board, ROW, COL);
}//Game函数结束
