#include <iostream>
#include "humanPlayer.h"
#include "board.h"

void fun(Player * p) {
    p->printName();
}

int main()
{

    std::string s1;
    s1="Hans";
    HumanPlayer * h=new HumanPlayer(s1,'B');
    fun(h);
    h->printName();
    //delete h;


    Board *b = new Board(8, 5);
    //if(b->setStone(2, h))
    //    std::cout << "TRUE";
    b->setStone(2, h);
    b->show();
    return 0;
}
