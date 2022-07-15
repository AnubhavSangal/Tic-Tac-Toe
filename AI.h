#ifndef _AI_H_
#define _AI_H_

#include<vector>
#include "AI_Bias.h"
#include "Board.h"

class AI
{
    private:
    std::vector<AI_Bias> AI_Biases;
    public:
    AI();
    int move(Board &board,int turn);
};

#endif //_AI_H_