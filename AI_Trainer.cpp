#include <fstream> 
#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include "Board.h"
#include "game.h"
#include "AI_Bias.h"
using namespace std;


int train(vector<AI_Bias> &AI)
{
    Board board;
    Game game;
    vector<pair<AI_Bias*,int>> moves1,moves2;
    int win_check{-1};
    int turn=1;
    for(int x=0;x<9;x++)
    {
        bool check{false};
        AI_Bias *bias;
        for(auto &a:AI)
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
            AI.push_back(bias1);
            bias=&AI[AI.size()-1];
        }
        int move=bias->next_move();
//        cout<<move<<endl;
//        cout<<board.get(move)<<endl;
        if(turn==1)
            moves1.push_back({bias,move});
        else
            moves2.push_back({bias,move});
        int game_check=game.move(board,move);
//            cout<<game_check<<endl;
        if((game_check!=0)&&(game_check!=1))
        {
            win_check=turn;
            break;
        }
        turn=1-turn;
    }
    int update1,update2;
    if(win_check==1)
    {
        update1=1;
        update2=-1;
    }
    else if(win_check==0)
    {
        update1=-1;
        update2=1;
    }
//    else
//    {
//        update1=-1;
//        update2=-1;
//    }
    if(win_check!=-1)
    {
    for(auto a:moves1)
        a.first->update_bias(a.second,update1);
    for(auto a:moves2)
        a.first->update_bias(a.second,update2);
    }
    if(win_check!=-1)
        return 1;
    else
        return 0;
//    int z;
//    cin>>z;
}

int main()
{
    srand(time(NULL));
    vector<AI_Bias> AI;
    std::ifstream fin;
    fin.open("AI_Biases.txt");
    while (fin)
    {
        std::string s;
        getline(fin,s);
        AI.push_back(AI_Bias(s));
    }
    fin.close();
    remove("AI_Biases.txt");
    long long n{},sum{};
    cout<<"Enter number of times to train: ";
    cin>>n;
    if(n<100)
        n=100;
    ofstream fout;
    fout.open("AI_Biases.txt");
    for(long long x=1;x<=n;x++)
    {
        sum+=train(AI);
        if(x%(n/100)==0)
        cout<<(x/(n/100))<<"%\t";
    }
    for(auto &it:AI)
        fout<<it.get_string()<<endl;
    cout<<endl<<"Win Percent: "<<((double)sum/n)<<"%"<<endl;
    cin>>n;
}