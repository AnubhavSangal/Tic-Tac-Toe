#include "AI.h"
#include "Board.h"
#include<string>
#include<sstream>
#include <fstream> 

AI::AI()
{
    std::ifstream fin;
    fin.open("AI_Biases.txt");
    while (fin)
    {
        std::string s;
        getline(fin,s);
        this->AI_Biases.push_back(AI_Bias(s));
    }
}

int AI::move(Board &board,int turn)
{
    bool check{false};
    AI_Bias *bias;
    for(auto &a:this->AI_Biases)
    {
        if(a.is_equal(board,turn))
        {
            bias=&a;
            check=true;
            break;
        }
    }
    if(!check)
    {
        AI_Bias bias1(board,turn);
        this->AI_Biases.push_back(bias1);
        bias=&this->AI_Biases[this->AI_Biases.size()-1];
    }
    return bias->next_move();
}