#ifndef _BOARD_H_
#define _BOARD_H_

class Board
{
    private:
    char moves[9];
    public:
    Board();
    char get(int index);
    char get(int x,int y);
    bool set(int index,char move);
    bool set(int index,int move);
    bool set(int x,int y,char move);
    bool set(int x,int y,int move);
    void reset();
    bool operator==(Board &board);
};

#endif //_BOARD_H_