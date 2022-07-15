#include<iostream>
#include "Board.h"

void display(Board &board)
{
    for(int y=0;y<3;y++)
    {
        for(int x=0;x<3;x++)
        {
            char c=board.get(x,y);
            if(c=='\0')
                std::cout<<((x+1)+(y*3));
            else
                std::cout<<c;
            if(x!=2)
                std::cout<<" | ";
        }
        std::cout<<std::endl;
        if(y!=2)
            std::cout<<"--+---+--\n";
    }
}

int play_choice()
{
    std::cout<<"Player VS Player\t(1)\nPlayer VS Computer\t(2)\n";
    std::cout<<"Enter your choice: ";
    int c;
    std::cin>>c;
    return c;
}

int move_choice(int c)
{
    int x;
    if(!c)
        std::cout<<"Enter Your Move: ";
    else
        std::cout<<"Enter Valid Move: ";
    std::cin>>x;
    return x;
}

bool next_choice()
{
    int c;
    std::cout<<"Play Again\t(1)\nExit\t\t(2)\n";
    std::cout<<"Enter your choice: ";
    std::cin>>c;
    if(c==1)
        return true;
    return false;
}

void dis_last(int move)
{
    std::cout<<"Last Move: "<<move<<std::endl;
}

void end_game(int c)
{
    switch (c)
    {
    case -1:
        std::cout<<"You Won!\n";
        break;
    case 0:
        std::cout<<"I Won!\n";
        break;
    case 1:
        std::cout<<"Player 1 Won!\n";
        break;
    case 2:
        std::cout<<"Player 2 Won!\n";
        break;
    default:
        std::cout<<"Draw\n";
        break;
    }
}

void clear()
{
    system("cls");
}