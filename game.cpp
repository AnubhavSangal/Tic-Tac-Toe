#include "Board.h"
#include "game.h"

Game::Game()
{
    this->reset();
}

void Game::reset()
{
    this->turn=1;
    this->turns=0;
}

int Game::move(Board &board,int index)
{
    bool check1=board.set(index,this->turn);
    if(!check1)
        return -1;
    this->turn=1-this->turn;
    this->turns++;
    int check2=this->check(board);
    if(!check2)
    {
        if(turns==9)
            return 1;
        else
            return 0;
    }
    else
        return check2;
}

int Game::check(Board &board)
{
    int c{0};
	for(int x=0;x<3;x++)
		if((board.get(x,0)==board.get(x,1))&&(board.get(x,1)==board.get(x,2))&&(board.get(x,1)!='\0'))
		{
			c=(x+1)+((x+1)+3)*10+((x+1)+6)*100;
			break;
		}
	if(!c)
		for(int x=0;x<3;x++)
			if((board.get(0,x)==board.get(1,x))&&(board.get(1,x)==board.get(2,x))&&(board.get(1,x)!='\0'))
			{
			    c=(1+(3*x))+(2+(3*x))*10+(3+(3*x))*100;
				break;
			}
	if(!c)
		if((board.get(0,0)==board.get(1,1))&&(board.get(1,1)==board.get(2,2))&&(board.get(1,1)!='\0'))
			c=159;
	if(!c)
		if((board.get(0,2)==board.get(1,1))&&(board.get(1,1)==board.get(2,0))&&(board.get(1,1)!='\0'))
			c=357;
	return c;
}