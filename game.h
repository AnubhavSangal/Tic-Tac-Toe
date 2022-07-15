#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"

class Game
{
    private:
    int turn;
    int turns;
    public:
    Game();
    int move(Board &board,int index);
    int check(Board &board);
    void reset();
};

#endif //_GAME_H_