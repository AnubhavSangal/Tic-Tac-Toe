#include "Board.h"

Board::Board()
{
    this->reset();
}

char Board::get(int index)
{
    if(index<1||index>9)
        return '\0';
    return this->moves[index-1];
}

char Board::get(int x,int y)
{
    if((x<0||x>2)||(y<0||y>2))
        return '\0';
    return get((x+1)+(y*3));
}

bool Board::set(int index,char move)
{
    if(this->get(index)!='\0')
        return false;
    if(move!='O'&&move!='X')
        return false;
    this->moves[index-1]=move;
    return true;
}

bool Board::set(int index,int move)
{
    if(move==0)
        return this->set(index,'O');
    if(move==1)
        return this->set(index,'X');
    return false;
}

bool Board::set(int x,int y,char move)
{
    if((x<0||x>2)||(y<0||y>2))
        return false;
    return this->set((x+1)+(y*3),move);
}

bool Board::set(int x,int y,int move)
{
    if((x<0||x>2)||(y<0||y>2))
        return false;
    return this->set((x+1)+(y*3),move);
}

void Board::reset()
{
    for(char &it:this->moves)
        it='\0';
}

bool Board::operator==(Board &board)
{
    for(int x=1;x<10;x++)
    {
        if(this->get(x)!=board.get(x))
            return false;
    }
    return true;
}
