#include <iostream>
#include "humanPlayer.h"
#include "board.h"

void fun(Player * p) {
    p->printName();
}

int main()
{
<<<<<<< HEAD
    Board *b = new Board(5, 7);
    //b->show();
    std::string s1, buffer;
=======

    std::string s1;
>>>>>>> origin/master
    s1="Hans";
    std::cin >> buffer;
    std::cout << buffer.at(0) <<std::endl;
    std::cin >> buffer;
    std::cout << buffer.at(0) <<std::endl;
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
