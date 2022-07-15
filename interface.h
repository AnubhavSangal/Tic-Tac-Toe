#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "Board.h"

void display(Board &board);
int play_choice();
int move_choice(int c);
bool next_choice();
void dis_last(int move);
void end_game(int c);
void clear();

#endif //_INTERFACE_H_