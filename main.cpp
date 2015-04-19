#include <iostream>
#include "humanPlayer.h"
#include "board.h"

void fun(Player * p) {
    p->printName();
}

int main()
{
    Board *b = new Board(5, 7);
    //b->show();
    std::string s1, buffer;
    s1="Hans";
    std::cin >> buffer;
    std::cout << buffer.at(0) <<std::endl;
    std::cin >> buffer;
    std::cout << buffer.at(0) <<std::endl;
    HumanPlayer * h=new HumanPlayer(s1,'B');
    fun(h);
    h->printName();
    delete h;
    return 0;
}
