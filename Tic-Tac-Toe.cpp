#include<stdlib.h>
#include<ctime>
#include<iostream>
#include "Board.h"
#include "AI.h"
#include "interface.h"
#include "game.h"

int input(Board &board,Game &game,int lm)
{
    int check{-1};
    int move;
    do
    {
        clear();
        display(board);
        std::cout<<std::endl;
        if(lm!=0)
            dis_last(lm);
        move=move_choice((check!=-1));
        check=game.move(board,move);
    }while(check==-1);
    if(check!=0&&check!=1)
        return 0;
    return move;
}

int main()
{
    srand(time(NULL));
    Board board;
    Game game;
    AI ai;
    int x;
	do{
		int t{0},k{0};
        int move{0};
		clear();
		k=play_choice();
		board.reset();
        game.reset();
		if(k==2)
		t=rand()%2;			
		int c=1;
		for(x=0;x<9;x++)
		{
			if(k==1)
                move=input(board,game,move);
			else
			{
				if(x%2==t)
				move=input(board,game,move);
				else
				{
                    move=ai.move(board,c);
                    int check=game.move(board,move);
                    if(check!=0&&check!=1)
                        move=0;
                }
			}
			if(!move)
			break;
			c=1-c;
		}
		clear();
		display(board);
		if(k==1)
		{
			if(x==9)
			end_game(3);
			else
			end_game(2-c);
		}
		else
		{
			if(x==9)
			end_game(3);
			else if((t==1&&c==1)||(t==2&&c==0))
			end_game(0);
			else
			end_game(-1);
		}
		x=next_choice();
	}while(x==1);
    return 0;
}
