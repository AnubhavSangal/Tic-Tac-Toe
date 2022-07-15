#include "AI_Bias.h"
#include<climits>
#include<ctime>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<iostream>


AI_Bias::AI_Bias(Board board,int turn)
{
    this->board=board;
    this->turn=turn;
    int n{};
    for(int x=0;x<9;x++)
    {
        if(board.get(x+1)=='\0')
            this->biases[x]=1000;
        else
            this->biases[x]=0;
    }
}

AI_Bias::AI_Bias(std::string init)
{
    std::stringstream s;
    s<<init;
    for(int x=1;x<10;x++)
    {
        char c;
        s>>c;
        if(c!='-')
            this->board.set(x,c);
    }
    s>>this->turn;
    for(int x=0;x<9;x++)
    {
        int b;
        s>>b;
        this->biases[x]=b;
    }
}

void AI_Bias::update_bias(int move,int update=1)
{
    if(update>0&&this->biases[move-1]==INT_MAX)
        return;
    long long sum{};
    for(int x=0;x<9;x++)
        sum+=this->biases[x];
    if((sum+update)<=0)
        return;
    biases[move-1]+=update;
    if(biases[move-1]<0)
        biases[move-1]=0;
}

bool AI_Bias::is_equal(Board board,int turn)
{
    if(this->board==board&&this->turn==turn)
        return true;
    return false;
}

int AI_Bias::next_move()
{
    long long sum{};
    for(int x=0;x<9;x++)
        sum+=this->biases[x];
    if(sum==0)
    {
        std::cout<<"zero"<<std::endl;
        int z;
        std::cin>>z;
    }
    int mv=rand()%sum+1;
    int x{};
    int i{};
    do
    {
        x+=this->biases[i++];
        if(mv<=x)
            return i;
    }while(x<=sum);
}

std::string AI_Bias::get_string()
{
    std::string r;
    for(int x=1;x<10;x++)
    {
        if(this->board.get(x)=='\0')
            r+='-';
        else
            r+=this->board.get(x);
    }
    r+=" ";
    r+=(char)(this->turn+'0');
    r+=" ";
    for(int x=0;x<9;x++)
        r+=std::to_string(this->biases[x])+" ";
    return r;
}