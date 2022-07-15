#ifndef _AI_BIAS_H_
#define _AI_BIAS_H

#include<string>
#include "Board.h"

class AI_Bias
{
    private:
    Board board;
    int turn;
    int biases[9];
    public:
    AI_Bias(Board board,int turn);
    AI_Bias(std::string init);
    void update_bias(int move,int update);
    int next_move();
    bool is_equal(Board board,int turn);
    std::string get_string();
};

#endif //_AI_BIAS_H_