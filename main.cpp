#include <iostream>
#include "humanPlayer.h"
#include "board.h"

void fun(Player * p) {
    p->printName();
}

int main()
{
    Board *b = new Board(5, 7);
    b->show();
    std::string s1;
    s1="Hans";
    HumanPlayer * h=new HumanPlayer(s1,'B');
    fun(h);
    h->printName();
    delete h;
    return 0;
}